#ifndef ACCOUNTANTWINDOW_H
#define ACCOUNTANTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "contractconfirmationwindow.h"
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include "abstractuserwindow.h"
#include <QSqlQueryModel>
#include "database.h"


namespace Ui {
class AccountantWindow;
}

class AccountantWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AccountantWindow(Database* database, QWidget *parent = nullptr);
    ~AccountantWindow();
private:
    Ui::AccountantWindow *ui;
    QTableView* viewContracts;
    ContractConfirmationWindow* confirmationWindow;
    QVBoxLayout* layoutParentWidgetConfirmContract;
    QSqlQueryModel* sqlModel;
    Database* db;

    void ConfiguringInterface();
    void ShowViewContracts();
    void ShowConfirmationWindow();
    void DeleteParentWidgetChildren();
private slots:
    void slotDoubleClikedOnContract(const QModelIndex index);
    void slotConfirmWidgetBackButtonClicked();
};

#endif // ACCOUNTANTWINDOW_H
