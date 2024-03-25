QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractuserwindow.cpp \
    accountantwindow.cpp \
    adminwindow.cpp \
    agentwindow.cpp \
    contractconfirmationwindow.cpp \
    database.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    profilewindow.cpp \
    renegotiatecontractwindow.cpp \
    user.cpp \
    windownavigator.cpp

HEADERS += \
    Global.h \
    abstractuserwindow.h \
    accountantwindow.h \
    adminwindow.h \
    agentwindow.h \
    contractconfirmationwindow.h \
    database.h \
    loginwindow.h \
    mainwindow.h \
    profilewindow.h \
    renegotiatecontractwindow.h \
    user.h \
    windownavigator.h

FORMS += \
    accountantwindow.ui \
    adminwindow.ui \
    agentwindow.ui \
    contractconfirmationwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    profilewindow.ui \
    renegotiatecontractwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
