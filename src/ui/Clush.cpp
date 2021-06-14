#include "Clush.hpp"
#include "LoginDialog.hpp"
#include "ui_Clush.h"
#include "util/ClushFrame.hpp"

#include <QCryptographicHash>

namespace clush {

Clush::Clush(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Clush)
    , socket(new QTcpSocket(this))
    , userListModel(new QStandardItemModel(this))
    , groupListModel(new QStandardItemModel(this))
{
    ui->setupUi(this);

    ui->userWidget->setModel(userListModel);
    ui->groupWidget->setModel(groupListModel);

    // TODO: read address from config file
    socket->connectToHost("127.0.0.1", 9527);
    connect(socket, &QTcpSocket::readyRead, this, &Clush::handleMessage);

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
    util::ClushFrame frame = util::ClushFrame();
    frame.msgType = util::MessageType::LoginMessage;
    frame.fromId = user.toUInt();
    frame.toId = 0;

    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    frame.content = hash;
    frame.updateSize();

    socket->write(frame.toBytes());
}

void Clush::handleMessage()
{}

} // namespace clush
