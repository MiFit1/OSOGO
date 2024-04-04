#ifndef ABSTRACTUSERWINDOW_H
#define ABSTRACTUSERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "profilewindow.h"
#include "QSidePanel/PanelLeftSide.hpp"
#include "user.h"

class AbstractUserWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AbstractUserWindow(const User& user, QWidget *parent = nullptr);
    ~AbstractUserWindow();

signals:
    void signalLogout();

public:
    QPushButton* profileButton;
    ProfileWindow* profileWindow;
    PanelLeftSide* profilePanel;
    User getUser();

protected:
    User user;
};

#endif // ABSTRACTUSERWINDOW_H
