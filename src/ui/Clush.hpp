#ifndef CLUSH_HPP
#define CLUSH_HPP

#include "DialogWidget.hpp"
#include "ContactWidget.hpp"

#include <QWidget>
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
    void handleLogin(const QString& user, const QString& password);

private:
    Ui::Clush* ui;

    QStandardItemModel* userListModel;
    QStandardItemModel* groupListModel;
};

} // namespace clush
#endif // CLUSH_HPP
