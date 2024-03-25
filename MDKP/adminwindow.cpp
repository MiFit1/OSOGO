#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QSize>

AdminWindow::AdminWindow(QWidget *parent) :
    AbstractUserWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    configuringInterface();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::configuringInterface(){
    //Кнопка профиля
    profileButton = new QPushButton(this);
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    profileWindow = new ProfileWindow();
    connect(profileButton,SIGNAL(clicked()),this,SLOT(slotProfileButtonClicked()));
    connect(profileWindow,SIGNAL(signalLogoutButtonClicked()),SLOT(slotLogoutButtonClicked()));
    //Размеры полей ввода
    //ui->LastName->setMinimumHeight(40);
}

void AdminWindow::slotProfileButtonClicked(){
    profileWindow->show();
}

void AdminWindow::slotLogoutButtonClicked(){
    emit signalLogout();
}
