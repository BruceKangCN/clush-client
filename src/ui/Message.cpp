#include "Message.hpp"
#include "ui_Message.h"

#include <QDateTime>

namespace clush {

Message::Message(const QString& content, QWidget* parent, bool rightAlign)
    : QWidget(parent)
    , ui(new Ui::Message)
{
    ui->setupUi(this);

    // get current date&time string, set label with it
    const QString now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->metaLabel->setText(now);
    // set content to viewer
    ui->contentViewer->setMarkdown(content);

    // set alignment decided by parameter
    if (rightAlign) {
        ui->metaLabel->setAlignment(Qt::AlignRight);
    }
}

Message::~Message()
{
    delete ui;
}

} // namespace clush
