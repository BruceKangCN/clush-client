#include "LoginDialog.hpp"
#include "ui_LoginDialog.h"

namespace clush {

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    // hide title bar
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
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
    const QString user = ui->userLE->text();
    const QString password = ui->passwordLE->text();

    emit requestLogin(user, password);

    // for test only, skip verification
    // TODO: verify
    this->accept();
}

} // namespace clush
