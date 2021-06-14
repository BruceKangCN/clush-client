#include "LoginDialog.hpp"
#include "ui_LoginDialog.h"

namespace clush {

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    // only enable the minimize button on title bar
    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_exitBtn_clicked()
{
    exit(EXIT_SUCCESS);
}

void LoginDialog::on_loginBtn_clicked()
{
    // first, disable login button
    ui->loginBtn->setEnabled(false);

    // get user info from line edit
    const QString user = ui->userLE->text();
    const QString password = ui->passwordLE->text();

    // emit login signal
    emit requestLogin(user, password);

    // for test only, skip verification
    // TODO: verify
    // this->accept();
}

void LoginDialog::loginSuccess()
{
    this->accept();
}

void LoginDialog::loginFailed() const
{
    // re-enable login button
    ui->loginBtn->setEnabled(true);
}

} // namespace clush
