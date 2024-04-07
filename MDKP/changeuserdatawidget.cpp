#include "changeuserdatawidget.h"
#include "ui_changeuserdatawidget.h"
#include "Global.h"

ChangeUserDataWidget::ChangeUserDataWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeUserDataWidget)
{
    ui->setupUi(this);

    //ui->Post->
    connect(ui->BackButton,SIGNAL(clicked()),SIGNAL(signalBackButtonCliked()));
}

ChangeUserDataWidget::~ChangeUserDataWidget()
{
    delete ui;
}

void ChangeUserDataWidget::setUserToChangeWidget(User user){
    this->user = user;
    ui->LastName->setText(user.GetLastName());
    ui->FirstName->setText(user.GetFirstName());
    ui->Patronymic->setText(user.GetPatronymic());
    ui->Phone->setText(user.GetPhone());
    ui->Address->setText(user.GetAddress());
    ui->Branch->setText(user.GetBranch());
    ui->LoginLine->setText(user.GetLogin());
    ui->PasswordLine->setText(user.GetPassword());
    QString postStr = user.convertPost(user.GetPost());
    ui->Post->setCurrentText(postStr);
}
