#include "windownavigator.h"

WindowNavigator::WindowNavigator(QObject *parent, Database* db)
    : QObject{parent}
{
    this->db = db;
    CreateAndShowLoginWindow();
}

void WindowNavigator::slotLoginSuccessful(const User& user){
    HideAndRemoveLoginWindow();
    switch (user.getRole()) {
    case Admin:{
        AdminWindow* window = new AdminWindow;
        windowForRole.reset(window);
    }
        break;

    case Accountant:{
        AccountantWindow* window = new AccountantWindow;
        windowForRole.reset(window);
    }
    break;

    case Agent:{
        AgentWindow* window = new AgentWindow;
        windowForRole.reset(window);
    }
    break;
    default:
        Q_ASSERT(false);
    }

    windowForRole->show();
    connect(windowForRole.get(),SIGNAL(signalLogout()),this,SLOT(slotLogout()));
}

void WindowNavigator::CreateAndShowLoginWindow(){
    loginWindow.reset(new LoginWindow);
    connect(loginWindow.get(), SIGNAL(signalLoginSuccessful(User)),this,SLOT(slotLoginSuccessful(User)));
    loginWindow->show();
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
