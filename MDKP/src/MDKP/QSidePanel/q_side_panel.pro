QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

TARGET = sidepanel

HEADERS += \
    ./QSidePanel/PanelBottomSide.hpp \
    ./QSidePanel/PanelLeftSide.hpp \
    ./QSidePanel/PanelRightSide.hpp \
    ./QSidePanel/PanelTopSide.hpp \
    ./QSidePanel/SidePanel.hpp \
    ./QSidePanel/SidePanelState.hpp \
    ./QSidePanel/math.hpp \
    ./QSidePanel/side_panel_helpers.hpp
    
SOURCES += \
    ./QSidePanel/PanelBottomSide.cpp \
    ./QSidePanel/PanelLeftSide.cpp \
    ./QSidePanel/PanelRightSide.cpp \
    ./QSidePanel/PanelTopSide.cpp \
    ./QSidePanel/SidePanel.cpp \
    ./QSidePanel/SidePanelState.cpp \
    ./QSidePanel/math.cpp \
    ./QSidePanel/side_panel_helpers.cpp

CONFIG += c++17
