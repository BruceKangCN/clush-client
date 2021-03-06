#include "Clush.hpp"
#include "ui_Clush.h"
#include "util/ClushFrame.hpp"

#include <QCryptographicHash>

namespace clush {

Clush::Clush(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Clush)
    , socket(new QTcpSocket(this))
    , loginDialog(new LoginDialog(this))
    , loginTimer(new QTimer(this))
    , userListModel(new QStandardItemModel(this))
    , groupListModel(new QStandardItemModel(this))
{
    ui->setupUi(this);

    // set models
    ui->userWidget->setModel(userListModel);
    ui->groupWidget->setModel(groupListModel);

    // connect to slots to handle login request and response
    connect(loginDialog, &LoginDialog::requestLogin, this, &Clush::handleLogin);
    connect(socket, &QTcpSocket::readyRead, this, &Clush::handleLoginResponse);
    connect(loginTimer, &QTimer::timeout, this, &Clush::handleLoginTimeout);
    loginDialog->exec();

    // disconnect after login success
    disconnect(socket, &QTcpSocket::readyRead, this, &Clush::handleLoginResponse);
    connect(loginTimer, &QTimer::timeout, this, &Clush::handleLoginTimeout);

    // connect to normal message handling slot
    connect(socket, &QTcpSocket::readyRead, this, &Clush::handleMessage);
}

Clush::~Clush()
{
    delete ui;
}

void Clush::handleLogin(const QString& user, const QString& password)
{
    // TODO: read address from config file
    socket->connectToHost("127.0.0.1", 9527);

    util::ClushFrame frame = util::ClushFrame();
    frame.msgType = util::MessageType::LoginMessage;
    frame.fromId = user.toULongLong();
    frame.toId = 0;

    // convert QString password to sha256 value
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    frame.content = hash;
    // update content size
    frame.updateSize();

    socket->write(frame.toBytes());
    loginTimer->start(30000); // timeout after 30s
}

void Clush::handleLoginResponse()
{
    util::ClushFrame frame = util::ClushFrame(socket->readAll());

    if (frame.msgType != util::MessageType::LoginMessage || frame.fromId != 0) {
        loginDialog->loginFailed();
    }

    QByteArray message = frame.content;
    if (message == QString("success").toUtf8()) {
        loginDialog->loginSuccess();
    } else {
        socket->disconnectFromHost();
        loginDialog->loginFailed();
    }
}

void Clush::handleLoginTimeout()
{
    loginTimer->stop();
    socket->disconnectFromHost();
    loginDialog->loginFailed();
}

void Clush::handleMessage()
{
}

} // namespace clush
