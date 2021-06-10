#include "Clush.hpp"
#include "ui_Clush.h"

#include <QDebug>

namespace clush {

Clush::Clush(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Clush)
    , server(new QTcpServer(this))
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    // validate for port line edit
    ui->portLE->setValidator(new QIntValidator(0, 65535, ui->portLE));
    ui->listenPortLE->setValidator(new QIntValidator(0, 65535, ui->listenPortLE));

    // set model for contact list
    ui->contactList->setModel(model);

    connect(server, &QTcpServer::newConnection, this, &Clush::receiveNewConnection);
    connect(model, &QStandardItemModel::dataChanged, this, &Clush::dialogChangeName);
}

Clush::~Clush()
{
    delete ui;
}

void Clush::on_listenBtn_clicked()
{
    const QString host = ui->ListenHostLE->text();
    const quint16 port = ui->listenPortLE->text().toUShort();

    server->listen(QHostAddress(host), port);

    // set readonly after listener created
    ui->ListenHostLE->setReadOnly(true);
    ui->listenPortLE->setReadOnly(true);
    ui->listenBtn->setEnabled(false);
}

void Clush::receiveNewConnection()
{
    // receive the TCP socket, get info
    QTcpSocket* socket = server->nextPendingConnection();
    QString addr = socket->peerAddress().toString();
    quint16 port = socket->peerPort();

    // create a new dialog with the socket
    DialogWidget* dialog = new DialogWidget(socket, this);
    dialogVec.append(dialog);

    // append a new row to the model
    QStandardItem* item = new QStandardItem(QString("%1:%2").arg(addr).arg(port));
    model->appendRow({item});
}

void Clush::on_connectBtn_clicked()
{
    // get address from lineEdit
    QString host = ui->hostLE->text();
    quint16 port = ui->portLE->text().toUShort();

    // try to connect to host
    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost(host, port);

    // create new row and dialog if connected
    connect(socket, &QTcpSocket::connected, this, [=] {
        QStandardItem* item = new QStandardItem(QString("%1:%2").arg(host).arg(port));
        model->appendRow({item});

        DialogWidget* dialog = new DialogWidget(socket, this);
        dialogVec.append(dialog);
    });
}

void Clush::on_contactList_clicked(const QModelIndex& index)
{
    // TODO: change index to id
    DialogWidget* dialog = dialogVec[index.row()];
    ui->splitter->widget(1)->hide();
    ui->splitter->replaceWidget(1, dialog);
    dialog->show();
}

void Clush::dialogChangeName(const QModelIndex& index)
{
    const quint64 rowId = index.row();
    const QString name = model->itemFromIndex(index)->text();
    dialogVec[rowId]->setName(name);
}

} // namespace clush
