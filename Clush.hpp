#ifndef CLUSH_HPP
#define CLUSH_HPP

#include "DialogWidget.hpp"

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Clush; }
QT_END_NAMESPACE

namespace clush {

class Clush : public QWidget
{
    Q_OBJECT

public:
    Clush(QWidget* parent = nullptr);
    ~Clush();

private slots:
    void receiveNewConnection();
    void dialogChangeName(const QModelIndex& index);

    void on_listenBtn_clicked(); // start listening when the button clicked
    void on_connectBtn_clicked();
    void on_contactList_clicked(const QModelIndex& index);

private:
    Ui::Clush* ui;

    QTcpServer* server;
    QStandardItemModel* model;

    QVector<DialogWidget*> dialogVec;
};

} // namespace clush
#endif // CLUSH_HPP
