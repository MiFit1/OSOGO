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
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");
    profilePanel->raise();

    //layout
    layoutParentWidgetConfirmContract = new QVBoxLayout(ui->ParentWidgetConfirmContract);
    viewContracts = new QTableView();
    confirmationWindow = new ContractConfirmationWindow();
    ShowViewContracts();
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
