#include "accountantwindow.h"
#include "ui_accountantwindow.h"


AccountantWindow::AccountantWindow(QWidget *parent) :
    AbstractUserWindow(parent),
    ui(new Ui::AccountantWindow)
{
    ui->setupUi(this);
    ConfiguringInterface();
}

AccountantWindow::~AccountantWindow()
{
    delete ui;
}

void AccountantWindow::ConfiguringInterface(){
    //Кнопка профиля
    profileButton = new QPushButton;
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    //layout
    layoutParentWidgetConfirmContract = new QVBoxLayout(ui->ParentWidgetConfirmContract);
    viewContracts = new QTableView();
    confirmationWindow = new ContractConfirmationWindow();
    ShowViewContracts();

    //Размеры полей ввода
    //ui->LastName->setMinimumHeight(40);

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

//установка родительского виджета для виджета представления контрактов и добаление его в layout
void AccountantWindow::ShowViewContracts(){
    DeleteParentWidgetChildren();
    viewContracts->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(viewContracts);
}

void AccountantWindow::ShowConfirmationWindow(){
    DeleteParentWidgetChildren();
    confirmationWindow->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(confirmationWindow);
}

//очистка layout у родительского виджета и удаления виджета из layout
void AccountantWindow::DeleteParentWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetConfirmContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetConfirmContract->removeItem(item);
        layoutParentWidgetConfirmContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetConfirmContract->update();
    }
}

void AccountantWindow::slotLogoutButtonClicked(){
    emit signalLogout();
}
