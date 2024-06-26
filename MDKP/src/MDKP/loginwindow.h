#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "Global.h"
#include "database.h"

#include <QStackedLayout>
#include <QWidget>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(Database* database, QWidget *parent = nullptr);
    ~LoginWindow();
    void SetEnabledGraphicsEffect(bool status);
private:
    Ui::LoginWindow *ui;
    Database* db;
    QList<QGraphicsDropShadowEffect*> shadowEffects;

    void AddShadow(QObject* obj);
    void ReadAndSetShadowSettings();
    int GetShadowSettings();
signals:
    void signalLoginSuccessful(const User& user);

private slots:
    void on_LoginButton_clicked();
};

#endif // LOGINWINDOW_H
