#include "profilewindow.h"
#include "ui_profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);
    connect(ui->LogoutButton, SIGNAL(clicked()),SIGNAL(signalLogoutButtonClicked()));
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}
