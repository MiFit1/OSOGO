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
    explicit AbstractUserWindow(QWidget *parent = nullptr);
    ~AbstractUserWindow();

signals:
    void signalLogout();

public:
    QPushButton* profileButton;
    ProfileWindow* profileWindow;
    PanelLeftSide* profilePanel;

    void setUser(const User& user);
private:
    User user;

};

#endif // ABSTRACTUSERWINDOW_H
