#ifndef CLUSH_UTIL_CLUSHFRAME_HPP
#define CLUSH_UTIL_CLUSHFRAME_HPP

#include <QByteArray>
#include <QObject>

namespace clush::util {

enum MessageType {
    Undefined = -1,
    LoginMessage = 0,
    UserMessage = 1,
    GroupMessage = 2,
    UserFileMessage = 3,
    GroupFileMessage = 4,
};

class ClushFrame : public QObject {
    Q_OBJECT
public:
    static QByteArray quint32ToBytes(quint32 n);
    static QByteArray quint64ToBytes(quint64 n);
    static ClushFrame fromBytes(const QByteArray& bytes);

    explicit ClushFrame(QObject* parent = nullptr);
    explicit ClushFrame(const QByteArray& bytes, QObject* parent = nullptr);

    void append(const QByteArray& other);
    void updateSize();
    QByteArray toBytes();

signals:

public:
    MessageType msgType;
    quint64 fromId;
    quint64 toId;
    quint64 size;
    QByteArray content;
};

} // namespace clush::util

#endif // CLUSH_UTIL_CLUSHFRAME_HPP
