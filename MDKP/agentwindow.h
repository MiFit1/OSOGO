#ifndef AGENTWINDOW_H
#define AGENTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include <QStackedWidget>
#include <QtSql>
#include "abstractuserwindow.h"
#include "database.h"
#include "agentstatisticmodel.h"
#include "renegotiatecontractwindow.h"

namespace Ui {
class AgentWindow;
}

class AgentWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AgentWindow(const User& us,Database* database, QWidget *parent = nullptr);
    ~AgentWindow();

private:
    Ui::AgentWindow *ui;
    void ConfiguringInterface();
    QTableView* viewRenegotiateContract;
    QTableView* viewStatistic;
    RenegotiateContractWindow* renegotiationContractWidget;
    QSqlQueryModel* sqlModelRenegotiate;
    AgentStatisticModel* sqlStatisticModel;
    Database* db;
    QStackedWidget* stackedWidgetRenegotiateContract;

    void ShowViewRenegotiateContract();
    void ShowRenegotiateContractWidget();
    void ClearContractDataUi();
    void viewRenegotiateContractRefresh();
    void CheckingContractDataFieldsEmpty();

private slots:
    void slotDoubleClikedOnRenegitiationContract(const QModelIndex index);
    void slotRenegotiateWidgetBackButtonClicked();
    void slotConcludeContractButtonClicked();
    void slotRenegotiateContractDataChanged();
    void slotHeaderInStatisticWidgetClicked(int index);
};

#endif // AGENTWINDOW_H
