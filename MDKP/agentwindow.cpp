#include "agentwindow.h"
#include "ui_agentwindow.h"

AgentWindow::AgentWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AgentWindow)
{
    ui->setupUi(this);
    ConfiguringInterface();
}

AgentWindow::~AgentWindow()
{
    delete ui;
}

void AgentWindow::ConfiguringInterface(){
    parentWidgetRenegotiationContract = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(parentWidgetRenegotiationContract,"Перезаключить договор");

    //Кнопка профиля
    QPushButton* btn = new QPushButton;
    btn->setIcon(QIcon(":/images/resources/settings.png"));
    btn->setIconSize(QSize(40, 40));
    btn->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(btn, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    //layout
    layoutParentWidgetRenegotiationContract = new QVBoxLayout(parentWidgetRenegotiationContract);
    viewRenegotiateContract = new QTableView();
    renegotiationContractWidget = new RenegotiateContractWindow();

    ShowViewRenegotiateContract();
}

void AgentWindow::ShowViewRenegotiateContract(){
    DeleteParentRenegotiationWidgetChildren();
    viewRenegotiateContract->setParent(parentWidgetRenegotiationContract);
    layoutParentWidgetRenegotiationContract->addWidget(viewRenegotiateContract);
}

void AgentWindow::ShowRenegotiateContractWidget(){
    DeleteParentRenegotiationWidgetChildren();
    renegotiationContractWidget->setParent(parentWidgetRenegotiationContract);
    layoutParentWidgetRenegotiationContract->addWidget(renegotiationContractWidget);
}

void AgentWindow::DeleteParentRenegotiationWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetRenegotiationContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetRenegotiationContract->removeItem(item);
        layoutParentWidgetRenegotiationContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetRenegotiationContract->update();
    }
}
