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
    explicit DialogWidget(QTcpSocket* socket ,QWidget* parent = nullptr);
    ~DialogWidget();

    void setName(const QString& name = "");

private slots:
    void on_tabWidget_tabBarClicked(int index);
    void on_sendBtn_clicked();
    void appendNewMessage();
    void keyPressEvent(QKeyEvent* ev);

private:
    Ui::DialogWidget* ui;

    QTcpSocket* socket;
};

} // namespace clush
#endif // DIALOGWIDGET_HPP
