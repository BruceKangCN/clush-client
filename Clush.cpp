#include "Clush.hpp"
#include "ui_Clush.h"
#include "LoginDialog.hpp"

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

    LoginDialog loginDialog = LoginDialog(this);
    // TODO: handle login message, exit when clicked [x]
    loginDialog.exec();
}

Clush::~Clush()
{
    delete ui;
}

} // namespace clush
