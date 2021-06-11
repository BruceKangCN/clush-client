#include "ContactWidget.hpp"
#include "ui_ContactWidget.h"

namespace clush {

ContactWidget::ContactWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ContactWidget)
{
    ui->setupUi(this);
}

ContactWidget::~ContactWidget()
{
    delete ui;
}

void ContactWidget::setModel(QStandardItemModel* model)
{
    ui->contactList->setModel(model);
}

} // namespace clush
