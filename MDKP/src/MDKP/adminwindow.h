#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "abstractuserwindow.h"
#include "changeuserdatawidget.h"
#include "database.h"
#include "Global.h"

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QTimer>
#include <QToolButton>
#include <QTableView>
#include <QLayoutItem>
#include <QHeaderView>
#include <QtSql>
#include <QStackedWidget>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QSize>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <stdexcept>

#include <QStackedLayout>

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

    QSqlQueryModel* usersModel;
    QTableView* viewUsers;
    ChangeUserDataWidget* changeUserDataWidget;
    QStackedWidget* stackedWidgetUserManagement;
    Database* db;
    QString defaulStyleSheetRegButton;

    void ShowViewUsers();
    void ShowChangeUserDataWidget();
    void RefreshDataView();
    void ClearDataRegistrationUserWidget();
    void CheckingFieldsEmpty();
    void SetValidationOnCreateUsers();
public slots:
    void slotBackButtonChangeUserWidgetCliked();
private slots:
    void slotDoubleClikedOnUser(const QModelIndex index);
    void slotRegistrationButtonClicked();
    //void slotRegistrationButtonDisable();
    //void slotRegistrationButtonEnable();
    void slotChangeUserConfirmButtonClicked();
};

#endif // ADMINWINDOW_H
