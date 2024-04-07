#include "profilewindow.h"
#include "ui_profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);

    AddShadowToChildren(this);
    connect(ui->LogoutButton, SIGNAL(clicked()),SIGNAL(signalLogoutButtonClicked()));
    connect(ui->CancelButton,SIGNAL(clicked()),SIGNAL(singalCancelButtonClicked()));
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::fillProfile(const User& user){
    if(!user.isEmpty()){
        ui->LastNameLine->setText(user.GetLastName());
        ui->FirstNameLine->setText(user.GetFirstName());
        ui->PatronymicLine->setText(user.GetPatronymic());
    }
}
