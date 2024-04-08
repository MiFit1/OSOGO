#ifndef ACCOUNTANTWINDOW_H
#define ACCOUNTANTWINDOW_H
#include "contractconfirmationwindow.h"
#include "abstractuserwindow.h"
#include "accountantmodelstatistics.h"
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QStackedWidget>
#include "database.h"


namespace Ui {
class AccountantWindow;
}

class AccountantWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AccountantWindow(const User& us, Database* database, QWidget *parent = nullptr);
    ~AccountantWindow();
private:
    Ui::AccountantWindow *ui;
    QTableView* viewContracts;
    QTableView* viewStatistics;
    ContractConfirmationWindow* confirmationWindow;
    QVBoxLayout* layoutParentWidgetStatistics;
    QStackedWidget* stackedWidgetConfirmContract;
    QSqlQueryModel* sqlModelContract;
    AccountantModelStatistics* sqlModelStatistics;
    Database* db;

    void ConfiguringInterface();
    void ShowViewContracts();
    void ShowConfirmationWindow();
    void UpdateViewContracts();
private slots:
    void slotDoubleClikedOnContract(const QModelIndex index);
    void slotConfirmWidgetBackButtonClicked();
    void slotContractUpdateAndReject();
    void slotContractUpdateAndConfirm();
};

#endif // ACCOUNTANTWINDOW_H
