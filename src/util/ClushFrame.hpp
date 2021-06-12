#ifndef CLUSH_UTIL_CLUSHFRAME_HPP
#define CLUSH_UTIL_CLUSHFRAME_HPP

#include <QObject>
#include <QByteArray>

namespace clush::util {

enum MessageType {
    Undefined = -1,
    LoginMessage = 0,
    UserMessage = 1,
    GroupMessage = 2,
    UserFileMessage = 3,
    GroupFileMessage = 4,
};

class ClushFrame : public QObject
{
    Q_OBJECT
public:
    static QByteArray quint32ToBytes(quint32 n);
    static QByteArray quint64ToBytes(quint64 n);

    explicit ClushFrame(QObject* parent = nullptr);

    void setType(const MessageType type);
    void append(const QByteArray& other);
    void updateSize();
    QByteArray toBytes();

signals:

private:
    MessageType msgType;
    quint64 fromId;
    quint64 toId;
    quint64 size;
    QByteArray content;

};

} // namespace clush::util

#endif // CLUSH_UTIL_CLUSHFRAME_HPP
