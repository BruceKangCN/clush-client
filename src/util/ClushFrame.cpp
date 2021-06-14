#include "ClushFrame.hpp"

namespace clush::util {

ClushFrame::ClushFrame(QObject* parent)
    : QObject(parent)
{
}

ClushFrame::ClushFrame(const QByteArray& bytes, QObject* parent)
{
    // return an empty frame if invalid
    if (bytes.size() < 28) {
        return;
    }

    msgType = static_cast<MessageType>(bytes.mid(0, 4).toUInt());
    fromId = bytes.mid(4, 8).toULongLong();
    toId = bytes.mid(12, 8).toULongLong();
    size = bytes.mid(20, 8).toULongLong();
    content = bytes.mid(28);
}

void ClushFrame::append(const QByteArray& other)
{
    this->content.append(other);
    updateSize(); // auto update size
}

void ClushFrame::updateSize()
{
    this->size = this->content.size();
}

QByteArray ClushFrame::toBytes()
{
    QByteArray ba = QByteArray();

    quint32 type = static_cast<quint32>(this->msgType);
    ba.append(quint32ToBytes(type));
    ba.append(quint64ToBytes(this->fromId));
    ba.append(quint64ToBytes(this->toId));
    ba.append(quint64ToBytes(this->size));
    ba.append(this->content);

    return ba;
}

QByteArray ClushFrame::quint32ToBytes(quint32 n)
{
    const qsizetype byteCount = sizeof(quint32);
    QByteArray ba = QByteArray(byteCount, 0);
    const qsizetype bitOfBytes = 8;

    for (int i = 1; i <= byteCount; i++) {
        ba[byteCount - i] = n & 0xff;
        n >>= bitOfBytes;
    }

    return ba;
}

QByteArray ClushFrame::quint64ToBytes(quint64 n)
{
    const qsizetype byteCount = sizeof(quint64);
    QByteArray ba = QByteArray(byteCount, 0);
    const qsizetype bitOfBytes = 8;

    for (int i = 1; i <= byteCount; i++) {
        ba[byteCount - i] = n & 0xff;
        n >>= bitOfBytes;
    }

    return ba;
}

} // namespace clush::util
