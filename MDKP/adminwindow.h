#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "abstractuserwindow.h"
#include "profilewindow.h"
#include "QSidePanel/PanelLeftSide.hpp"

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
    PanelLeftSide* profilePanel;

    void configuringInterface();
private slots:
    void slotLogoutButtonClicked();
};

#endif // ADMINWINDOW_H
