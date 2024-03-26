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
#include "abstractuserwindow.h"
#include "profilewindow.h"
#include "QSidePanel/PanelLeftSide.hpp"

namespace Ui {
class AgentWindow;
}

class AgentWindow : public AbstractUserWindow
{
    Q_OBJECT

public:
    explicit AgentWindow(QWidget *parent = nullptr);
    ~AgentWindow();

private:
    Ui::AgentWindow *ui;
    void ConfiguringInterface();
    QWidget* parentWidgetRenegotiationContract;
    QVBoxLayout* layoutParentWidgetRenegotiationContract;
    QTableView* viewRenegotiateContract;
    RenegotiateContractWindow* renegotiationContractWidget;

    QPushButton* profileButton;
    ProfileWindow* profileWindow;
    PanelLeftSide* profilePanel;

    void ShowViewRenegotiateContract();
    void ShowRenegotiateContractWidget();
    void DeleteParentRenegotiationWidgetChildren();

private slots:
    void slotLogoutButtonClicked();
};

#endif // AGENTWINDOW_H
