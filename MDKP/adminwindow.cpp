#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QSize>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
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
    QPushButton* btn = new QPushButton;
    btn->setIcon(QIcon(":/images/resources/settings.png"));
    btn->setIconSize(QSize(40, 40));
    btn->setMinimumHeight(50);
    ui->tabWidget->setCornerWidget(btn, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");

    //Размеры полей ввода
    //ui->LastName->setMinimumHeight(40);
}

