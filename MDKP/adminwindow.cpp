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
    delete profileWindow;
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

void AdminWindow::slotLogoutButtonClicked(){
    emit signalLogout();
}

