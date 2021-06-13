#include "Clush.hpp"
#include "LoginDialog.hpp"
#include "ui_Clush.h"

namespace clush {

Clush::Clush(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Clush)
    , userListModel(new QStandardItemModel(this))
    , groupListModel(new QStandardItemModel(this))
{
    ui->setupUi(this);

    ui->userWidget->setModel(userListModel);
    ui->groupWidget->setModel(groupListModel);

    LoginDialog* loginDialog = new LoginDialog(this);
    connect(loginDialog, &LoginDialog::requestLogin, this, &Clush::handleLogin);
    loginDialog->exec();
    delete loginDialog;
}

Clush::~Clush()
{
    delete ui;
}

void Clush::handleLogin(const QString& user, const QString& password)
{
    // TODO: handle login
}

} // namespace clush
