#include "agentwindow.h"
#include "ui_agentwindow.h"

AgentWindow::AgentWindow(QWidget *parent)
    : AbstractUserWindow(parent)
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
    profileButton = new QPushButton;
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    //layout
    layoutParentWidgetRenegotiationContract = new QVBoxLayout(parentWidgetRenegotiationContract);
    viewRenegotiateContract = new QTableView();
    renegotiationContractWidget = new RenegotiateContractWindow();

    ShowViewRenegotiateContract();

    //Настройка боковой панели профиля
    profilePanel = new PanelLeftSide(this);
    profilePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    profilePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    profilePanel->init(profileButton);

    profileWindow = new ProfileWindow();
    profilePanel->setPanelSize(profileWindow->size().width()+5);
    profilePanel->setWidgetResizable(true);
    profilePanel->setWidget(profileWindow);


    connect(profileWindow,SIGNAL(signalLogoutButtonClicked()),SLOT(slotLogoutButtonClicked()));
    connect(profileWindow,SIGNAL(singalCancelButtonClicked()),profileButton, SIGNAL(clicked()));
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

void AgentWindow::slotLogoutButtonClicked(){
    emit signalLogout();
}

