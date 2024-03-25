#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "abstractuserwindow.h"
#include "profilewindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
private:
    Ui::AdminWindow *ui;
    QPushButton* profileButton;
    ProfileWindow* profileWindow;

    void configuringInterface();
private slots:
    void slotProfileButtonClicked();
    void slotLogoutButtonClicked();
};

#endif // ADMINWINDOW_H
