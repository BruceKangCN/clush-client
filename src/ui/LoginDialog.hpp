#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include <QDialog>

namespace Ui {
class LoginDialog;
}

namespace clush {

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = nullptr);
    ~LoginDialog();

signals:
    void requestLogin(const QString& user, const QString& password);

private slots:
    void loginSuccess();
    void loginFailed() const;

    void on_exitBtn_clicked();
    void on_loginBtn_clicked();

private:
    Ui::LoginDialog* ui;
};

} // namespace clush
#endif // LOGINDIALOG_HPP
