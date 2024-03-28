#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "abstractuserwindow.h"
#include "usertablemodel.h"
#include <QVBoxLayout>
#include <QTableView>
#include "changeuserdatawidget.h"
#include <QLayoutItem>
#include <QHeaderView>


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
    void configuringInterface();
    UserTableModel* u_model;

    QTableView* viewUsers;
    ChangeUserDataWidget* changeUserDataWidget;
    QVBoxLayout* layoutParentWidgetChangeUserData;

    void ShowViewUsers();
    void ShowChangeUserDataWidget();
    void DeleteParentWidgetChildren();
private slots:
    void slotDoubleClikedOnUser(const QModelIndex index);
};

#endif // ADMINWINDOW_H
