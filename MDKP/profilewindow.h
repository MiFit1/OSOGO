#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "user.h"
#include "Global.h"

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();
    void fillProfile(const User& user);
private:
    Ui::ProfileWindow *ui;
signals:
    void signalLogoutButtonClicked();
    void singalCancelButtonClicked();
};

#endif // PROFILEWINDOW_H
