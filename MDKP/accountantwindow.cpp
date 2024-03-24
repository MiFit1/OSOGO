#include "accountantwindow.h"
#include "ui_accountantwindow.h"

AccountantWindow::AccountantWindow(QWidget *parent) :
    QMainWindow(parent),
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
    QPushButton* btn = new QPushButton;
    btn->setIcon(QIcon(":/images/resources/settings.png"));
    btn->setIconSize(QSize(40, 40));
    btn->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(btn, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    //Размеры полей ввода
    //ui->LastName->setMinimumHeight(40);
    layoutParentWidgetConfirmContract = new QVBoxLayout(ui->ParentWidgetConfirmContract);
    viewContracts = new QTableView();
    confirmationWindow = new ContractConfirmationWindow();
    ShowViewContracts();
}

void AccountantWindow::ShowViewContracts(){
    QLayoutItem* item = layoutParentWidgetConfirmContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetConfirmContract->removeItem(item);
        layoutParentWidgetConfirmContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetConfirmContract->update();
    }
    viewContracts->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(viewContracts);
}

void AccountantWindow::ShowConfirmationWindow(){
    QLayoutItem* item = layoutParentWidgetConfirmContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetConfirmContract->removeItem(item);
        layoutParentWidgetConfirmContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetConfirmContract->update();
    }
    confirmationWindow->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(confirmationWindow);
}

