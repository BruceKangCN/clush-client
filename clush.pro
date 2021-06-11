QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ContactWidget.cpp \
    DialogWidget.cpp \
    LoginDialog.cpp \
    Message.cpp \
    main.cpp \
    Clush.cpp

HEADERS += \
    Clush.hpp \
    ContactWidget.hpp \
    DialogWidget.hpp \
    LoginDialog.hpp \
    Message.hpp

FORMS += \
    Clush.ui \
    ContactWidget.ui \
    DialogWidget.ui \
    LoginDialog.ui \
    Message.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LICENSE \
    README.md
