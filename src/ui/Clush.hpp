#ifndef CLUSH_HPP
#define CLUSH_HPP

#include "ContactWidget.hpp"
#include "DialogWidget.hpp"
#include "LoginDialog.hpp"

#include <QStandardItem>
#include <QStandardItemModel>
#include <QTcpSocket>
#include <QTimer>
#include <QVector>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Clush;
}
QT_END_NAMESPACE

namespace clush {

class Clush : public QWidget {
    Q_OBJECT

public:
    Clush(QWidget* parent = nullptr);
    ~Clush();

private slots:
    void handleLogin(const QString& user, const QString& password);
    void handleLoginResponse();
    void handleLoginTimeout();
    void handleMessage();

private:
    Ui::Clush* ui;

    QTcpSocket* socket;
    LoginDialog* loginDialog;
    QTimer* loginTimer;

    QStandardItemModel* userListModel;
    QStandardItemModel* groupListModel;
};

} // namespace clush
#endif // CLUSH_HPP
