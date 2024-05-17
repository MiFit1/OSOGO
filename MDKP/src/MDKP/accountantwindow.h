#ifndef ACCOUNTANTWINDOW_H
#define ACCOUNTANTWINDOW_H
#include "contractconfirmationwindow.h"
#include "abstractuserwindow.h"
#include "accountantmodelstatistics.h"
#include "QSidePanel/QSidePanel/PanelLeftSide.hpp"
#include "tariffratewidget.h"
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
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
    QPushButton* tariffRateButton;
    QWidget* tabCornerWidget;
    QHBoxLayout* tabCornerWidgetLayout;
    PanelLeftSide* tariffRatePanel;
    TariffRateWidget* tariffRateWidget;

    void ConfiguringInterface(User user);
    void ShowViewContracts();
    void ShowConfirmationWindow();
    void UpdateViewContracts();
private slots:
    void slotDoubleClikedOnContract(const QModelIndex index);
    void slotConfirmWidgetBackButtonClicked();
    void slotConfirmContractButtonClicked();
    void slotRejectContractButtonClicked();
    void slotHeaderInStatisticWidgetClicked(int index);
};

#endif // ACCOUNTANTWINDOW_H
