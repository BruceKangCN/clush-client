#include "ui/Clush.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    clush::Clush w;
    w.show();
    return a.exec();
}
