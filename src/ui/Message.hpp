#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QWidget>

namespace Ui {
class Message;
}

namespace clush {

class Message : public QWidget {
    Q_OBJECT

public:
    explicit Message(const QString& content, QWidget* parent = nullptr, bool rightAlign = false);
    ~Message();

private:
    Ui::Message* ui;
};

} // namespace clush
#endif // MESSAGE_HPP
