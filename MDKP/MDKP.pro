QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = q_side_panel_proj
TEMPLATE = app

include($${PWD}/QSidePanel/q_side_panel.pri)

SOURCES += \
    Global.cpp \
    abstractuserwindow.cpp \
    accountantmodelstatistics.cpp \
    accountantwindow.cpp \
    adminwindow.cpp \
    agentstatisticmodel.cpp \
    agentwindow.cpp \
    changeuserdatawidget.cpp \
    client.cpp \
    comment.cpp \
    contract.cpp \
    contractconfirmationwindow.cpp \
    database.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    phoneedit.cpp \
    profilewindow.cpp \
    renegotiatecontractwindow.cpp \
    tariffratewidget.cpp \
    user.cpp \
    windownavigator.cpp

HEADERS += \
    Global.h \
    abstractuserwindow.h \
    accountantmodelstatistics.h \
    accountantwindow.h \
    adminwindow.h \
    agentstatisticmodel.h \
    agentwindow.h \
    changeuserdatawidget.h \
    client.h \
    comment.h \
    contract.h \
    contractconfirmationwindow.h \
    database.h \
    loginwindow.h \
    mainwindow.h \
    phoneedit.h \
    profilewindow.h \
    renegotiatecontractwindow.h \
    tariffratewidget.h \
    user.h \
    windownavigator.h

FORMS += \
    accountantwindow.ui \
    adminwindow.ui \
    agentwindow.ui \
    changeuserdatawidget.ui \
    contractconfirmationwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    profilewindow.ui \
    renegotiatecontractwindow.ui \
    tariffratewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    QSidePanel/q_side_panel.pri
