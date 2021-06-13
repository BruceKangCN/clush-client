QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
        ui \
        util

SOURCES += \
    main.cpp \
    ui/ContactWidget.cpp \
    ui/DialogWidget.cpp \
    ui/LoginDialog.cpp \
    ui/Message.cpp \
    ui/Clush.cpp \
    util/ClushFrame.cpp

HEADERS += \
    ui/Clush.hpp \
    ui/ContactWidget.hpp \
    ui/DialogWidget.hpp \
    ui/LoginDialog.hpp \
    ui/Message.hpp \
    util/ClushFrame.hpp

FORMS += \
    ui/Clush.ui \
    ui/ContactWidget.ui \
    ui/DialogWidget.ui \
    ui/LoginDialog.ui \
    ui/Message.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
