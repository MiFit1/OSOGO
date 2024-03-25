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

namespace Ui {
class AgentWindow;
}

class AgentWindow : public QMainWindow
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

    void ShowViewRenegotiateContract();
    void ShowRenegotiateContractWidget();
    void DeleteParentRenegotiationWidgetChildren();
};

#endif // AGENTWINDOW_H
