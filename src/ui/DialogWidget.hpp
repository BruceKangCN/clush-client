#ifndef DIALOGWIDGET_HPP
#define DIALOGWIDGET_HPP

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class DialogWidget;
}

namespace clush{

class DialogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DialogWidget(QWidget* parent = nullptr);
    ~DialogWidget();

    void setName(const QString& name = "");

private slots:
    void appendNewMessage();
    void keyPressEvent(QKeyEvent* ev);

    void on_tabWidget_tabBarClicked(int index);
    void on_sendBtn_clicked();

private:
    Ui::DialogWidget* ui;
};

} // namespace clush
#endif // DIALOGWIDGET_HPP
