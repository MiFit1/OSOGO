#ifndef AGENTWINDOW_H
#define AGENTWINDOW_H

#include "renegotiatecontractwindow.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QLayoutItem>
#include <QtSql>
#include "abstractuserwindow.h"
#include "database.h"

namespace Ui {
class AgentWindow;
}

class AgentWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AgentWindow(Database* database, QWidget *parent = nullptr);
    ~AgentWindow();

private:
    Ui::AgentWindow *ui;
    void ConfiguringInterface();
    QWidget* parentWidgetRenegotiationContract;
    QVBoxLayout* layoutParentWidgetRenegotiationContract;
    QTableView* viewRenegotiateContract;
    RenegotiateContractWindow* renegotiationContractWidget;
    QSqlQueryModel* sqlModelRenegotiate;
    Database* db;

    void ShowViewRenegotiateContract();
    void ShowRenegotiateContractWidget();
    void DeleteParentRenegotiationWidgetChildren();

private slots:
    void slotDoubleClikedOnRenegitiationContract(const QModelIndex index);
    void slotRenegotiateWidgetBackButtonClicked();

};

#endif // AGENTWINDOW_H
