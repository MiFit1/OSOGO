#include "ui_adminwindow.h"
#include "adminwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QSize>

AdminWindow::AdminWindow(QWidget *parent) :
    AbstractUserWindow(parent),
    ui(new Ui::AdminWindow)
{
    qDebug() << "call constructor";
    ui->setupUi(this);
    configuringInterface();
}

AdminWindow::~AdminWindow()
{
    qDebug() << "call destructor";
    delete ui;
}

void AdminWindow::configuringInterface(){
    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");
    profilePanel->raise();

    layoutParentWidgetChangeUserData = new QVBoxLayout(ui->ParentWidget);
    viewUsers = new QTableView();
    changeUserDataWidget = new ChangeUserDataWidget();
    ShowViewUsers();

    u_model = new UserTableModel(this);
    viewUsers->setModel(u_model);
}

void AdminWindow::ShowViewUsers(){
    DeleteParentWidgetChildren();
    viewUsers->setParent(ui->ParentWidget);
    layoutParentWidgetChangeUserData->addWidget(viewUsers);
}

void AdminWindow::ShowChangeUserDataWidget(){
    DeleteParentWidgetChildren();
    changeUserDataWidget->setParent(ui->ParentWidget);
    layoutParentWidgetChangeUserData->addWidget(changeUserDataWidget);
}

void AdminWindow::DeleteParentWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetChangeUserData->itemAt(0);
    if(item != NULL){
        layoutParentWidgetChangeUserData->removeItem(item);
        layoutParentWidgetChangeUserData->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetChangeUserData->update();
    }
}

