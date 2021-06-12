#include "DialogWidget.hpp"
#include "ui_DialogWidget.h"
#include "Message.hpp"

#include <QHostAddress>
#include <QKeyEvent>

namespace clush {

DialogWidget::DialogWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DialogWidget)
{
    ui->setupUi(this);
}

DialogWidget::~DialogWidget()
{
    delete ui;
}

void DialogWidget::setName(const QString& name)
{
    ui->name->setText(name);
}

void DialogWidget::on_tabWidget_tabBarClicked(int index)
{
    // if switch to preview
    if (index == 1) {
        // get content in editor, set to preview as markdown
        const QString content = ui->editor->toPlainText();
        ui->preview->setMarkdown(content);
    }
}

void DialogWidget::on_sendBtn_clicked()
{
//    // if not connected, append an error message and return
//    if (socket->state() != QTcpSocket::ConnectedState) {
//        const QString content = "# error\n**not connected**";
//        Message* msg = new Message(content, this, true);
//        ui->msgLayout->addWidget(msg);
//        return;
//    }

//    // get content and write
//    const QString content = ui->editor->toPlainText();
//    socket->write(content.toUtf8());

//    // append new message to viewer
//    Message* msg = new Message(content, this, true);
//    ui->msgLayout->addWidget(msg);

//    // clear the editor
//    ui->editor->setText("");
}

void DialogWidget::appendNewMessage()
{
//    const QString content = QString::fromUtf8(socket->readAll());
//    Message* msg = new Message(content, this);
//    ui->msgLayout->addWidget(msg);
}

void DialogWidget::keyPressEvent(QKeyEvent* ev)
{
    switch (ev->key()) {
    case Qt::Key_Enter:
    case Qt::Key_Return:
        on_sendBtn_clicked();
        break;
    default:
        break;
    }
}

} // namespace clush
