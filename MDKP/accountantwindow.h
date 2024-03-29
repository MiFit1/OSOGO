#ifndef ACCOUNTANTWINDOW_H
#define ACCOUNTANTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "contractconfirmationwindow.h"
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include "abstractuserwindow.h"
#include <QSqlQueryModel>>


namespace Ui {
class AccountantWindow;
}

class AccountantWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AccountantWindow(QWidget *parent = nullptr);
    ~AccountantWindow();
private:
    Ui::AccountantWindow *ui;
    QTableView* viewContracts;
    ContractConfirmationWindow* confirmationWindow;
    QVBoxLayout* layoutParentWidgetConfirmContract;
    QSqlQueryModel* model;

    void ConfiguringInterface();
    void ShowViewContracts();
    void ShowConfirmationWindow();
    void DeleteParentWidgetChildren();
};

#endif // ACCOUNTANTWINDOW_H
