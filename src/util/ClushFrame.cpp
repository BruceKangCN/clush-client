#include "ClushFrame.hpp"

#include <QtEndian>

namespace clush::util {

ClushFrame::ClushFrame(QObject* parent) : QObject(parent)
{

}

void ClushFrame::setType(const MessageType type)
{
    this->msgType = type;
}

void ClushFrame::append(const QByteArray& other)
{
    this->content.append(other);
}

void ClushFrame::updateSize()
{
    this->size = this->content.size();
}

QByteArray ClushFrame::toBytes()
{
    QByteArray ba = QByteArray();

    quint32 type = static_cast<quint32>(this->msgType);
    ba.append(qToBigEndian(type));
    ba.append(qToBigEndian(this->fromId));
    ba.append(qToBigEndian(this->toId));
    ba.append(qToBigEndian(this->size));
    ba.append(this->content);

    return ba;
}

} // namespace clush::util
