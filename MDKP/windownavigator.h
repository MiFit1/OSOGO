#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include "Global.h"
#include <QObject>
#include "database.h"
#include "loginwindow.h"
#include "accountantwindow.h"
#include "agentwindow.h"
#include "adminwindow.h"
#include "abstractuserwindow.h"
#include "user.h"
#include <QMessageBox>

class WindowNavigator : public QObject
{
    Q_OBJECT
public:
    explicit WindowNavigator(QObject *parent = nullptr, Database* db = nullptr);
private:
    Database* db;
    std::unique_ptr<AbstractUserWindow> windowForRole;
    std::unique_ptr<LoginWindow> loginWindow;

    void CreateAndShowLoginWindow();
    void HideAndRemoveLoginWindow();
    void HideAndRemoveRoleWindow();
public slots:
    void slotLoginSuccessful(const User& user);
    void slotLogout();
};

#endif // WINDOWNAVIGATOR_H
