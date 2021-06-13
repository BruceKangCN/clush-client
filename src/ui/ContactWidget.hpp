#ifndef CONTACTWIDGET_HPP
#define CONTACTWIDGET_HPP

#include <QStandardItemModel>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ContactWidget;
}
QT_END_NAMESPACE

namespace clush {

class ContactWidget : public QWidget {
    Q_OBJECT

public:
    explicit ContactWidget(QWidget* parent = nullptr);
    ~ContactWidget();

    void setModel(QStandardItemModel* model);

private:
    Ui::ContactWidget* ui;
};

} // namespace clush
#endif // CONTACTWIDGET_HPP
