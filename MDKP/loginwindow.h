#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "Global.h"
#include "database.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(Database* database, QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    Database* db;

signals:
    void signalLoginSuccessful(const User& user);

private slots:
    void on_LoginButton_clicked();
};

#endif // LOGINWINDOW_H
