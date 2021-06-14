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

    // set models
    ui->userWidget->setModel(userListModel);
    ui->groupWidget->setModel(groupListModel);

    // TODO: read address from config file
    socket->connectToHost("127.0.0.1", 9527);

    LoginDialog* loginDialog = new LoginDialog(this);
    // connect to slots to handle login request and response
    connect(loginDialog, &LoginDialog::requestLogin, this, &Clush::handleLogin);
    connect(socket, &QTcpSocket::readyRead, this, &Clush::handleLoginResponse);
    loginDialog->exec();

    // disconnect after login success, release the memory
    disconnect(socket, &QTcpSocket::readyRead, this, &Clush::handleLoginResponse);
    delete loginDialog;

    // connect to normal message handling slot
    connect(socket, &QTcpSocket::readyRead, this, &Clush::handleMessage);
}

Clush::~Clush()
{
    delete ui;
}

void Clush::handleLogin(const QString& user, const QString& password)
{
    util::ClushFrame frame = util::ClushFrame();
    frame.msgType = util::MessageType::LoginMessage;
    frame.fromId = user.toUInt();
    frame.toId = 0;

    // convert QString password to sha256 value
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    frame.content = hash;
    // update content size
    frame.updateSize();

    socket->write(frame.toBytes());
}

void Clush::handleLoginResponse()
{
}

void Clush::handleMessage()
{
}

} // namespace clush
