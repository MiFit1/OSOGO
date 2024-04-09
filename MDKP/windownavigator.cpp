#include "windownavigator.h"

WindowNavigator::WindowNavigator(QObject *parent, Database* db)
    : QObject{parent}
{
    this->db = db;
    CreateAndShowLoginWindow();
}

void WindowNavigator::slotLoginSuccessful(const User& user){
    HideAndRemoveLoginWindow();
    qDebug()<<user.GetId()<<" WindwowNavigator";
    switch (user.getRole()) {
    case Admin:{
        AdminWindow* window = new AdminWindow(user,db);
        windowForRole.reset(window);
    }
        break;

    case Accountant:{
        AccountantWindow* window = new AccountantWindow(user,db);
        windowForRole.reset(window);
    }
    break;

    case Agent:{
        AgentWindow* window = new AgentWindow(user,db);
        windowForRole.reset(window);
    }
    break;
    default:
        Q_ASSERT(false);
    }


    windowForRole->showMaximized();
    connect(windowForRole.get(),SIGNAL(signalLogout()),this,SLOT(slotLogout()));
}

void WindowNavigator::CreateAndShowLoginWindow(){
    loginWindow.reset(new LoginWindow(db));
    connect(loginWindow.get(), SIGNAL(signalLoginSuccessful(User)),this,SLOT(slotLoginSuccessful(User)));
    loginWindow->showMaximized();
}

void WindowNavigator::HideAndRemoveLoginWindow(){
    loginWindow->hide();
    loginWindow.reset();
}

void WindowNavigator::HideAndRemoveRoleWindow(){
    windowForRole->hide();
    windowForRole.reset();
}

void WindowNavigator::slotLogout(){
    HideAndRemoveRoleWindow();
    CreateAndShowLoginWindow();
}
