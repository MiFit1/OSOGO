#ifndef ABSTRACTUSERWINDOW_H
#define ABSTRACTUSERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "profilewindow.h"
#include "QSidePanel/PanelLeftSide.hpp"

class AbstractUserWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AbstractUserWindow(QWidget *parent = nullptr);
    ~AbstractUserWindow();

signals:
    void signalLogout();

public:
    QPushButton* profileButton;
    ProfileWindow* profileWindow;
    PanelLeftSide* profilePanel;
};

#endif // ABSTRACTUSERWINDOW_H
