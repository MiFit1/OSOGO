#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "abstractuserwindow.h"
#include "usertablemodel.h"
#include "changeuserdatawidget.h"
#include "database.h"

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include <QHeaderView>
#include <QtSql>


namespace Ui {
class AdminWindow;
}

class AdminWindow : public AbstractUserWindow
{
Q_OBJECT

public:
    explicit AdminWindow(const User& us,Database* database,QWidget *parent = nullptr);
    ~AdminWindow();
private:
    Ui::AdminWindow *ui;
    void configuringInterface();
    UserTableModel* u_model;

    QSqlQueryModel* usersModel;
    QTableView* viewUsers;
    ChangeUserDataWidget* changeUserDataWidget;
    QVBoxLayout* layoutParentWidgetChangeUserData;

    void ShowViewUsers();
    void ShowChangeUserDataWidget();
    void DeleteParentWidgetChildren();
    void AddShadowToChildren(QObject* obj);
public slots:
    void slotBackButtonChangeUserWidgetCliked();
private slots:
    void slotDoubleClikedOnUser(const QModelIndex index);
};

#endif // ADMINWINDOW_H
