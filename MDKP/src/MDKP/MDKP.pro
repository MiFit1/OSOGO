QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#TEMPLATE = app

#include($${PWD}/QSidePanel/q_side_panel.pri)
#include($${PWD}/Tests/Tests.pro)
#include($${PWD}/WidgetAnimationFramework/waf.pri)

#include($${PWD}/QSidePanel/q_side_panel.pro)
#TEMPLATE = subdirs
#SUBDIRS = \
    #Tests/Tests.pro
#LIBS += -L./QSidePanel -lsidepanel
#LIBS += -L./QSidePanel -lsidepanel
#TEMPLATE = subdirs
    #SUBDIRS += \
    #$${PWD} \
    #Tests

#Tests.depends = $$TARGET
#PRE_TARGETDEPS += $$Tests.target

INCLUDEPATH += ./QSidePanel/QSidePanel
SOURCES += \
    ./QSidePanel/QSidePanel/PanelBottomSide.cpp \
    ./QSidePanel/QSidePanel/PanelLeftSide.cpp \
    ./QSidePanel/QSidePanel/PanelRightSide.cpp \
    ./QSidePanel/QSidePanel/PanelTopSide.cpp \
    ./QSidePanel/QSidePanel/SidePanel.cpp \
    ./QSidePanel/QSidePanel/SidePanelState.cpp \
    ./QSidePanel/QSidePanel/math.cpp \
    ./QSidePanel/QSidePanel/side_panel_helpers.cpp \
    numberedit.cpp

HEADERS += \
    ./QSidePanel/QSidePanel/PanelBottomSide.hpp \
    ./QSidePanel/QSidePanel/PanelLeftSide.hpp \
    ./QSidePanel/QSidePanel/PanelRightSide.hpp \
    ./QSidePanel/QSidePanel/PanelTopSide.hpp \
    ./QSidePanel/QSidePanel/SidePanel.hpp \
    ./QSidePanel/QSidePanel/SidePanelState.hpp \
    ./QSidePanel/QSidePanel/math.hpp \
    ./QSidePanel/QSidePanel/side_panel_helpers.hpp \
    numberedit.h

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
