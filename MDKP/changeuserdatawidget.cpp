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
    connect(ui->ConfirmButton,SIGNAL(clicked()),SIGNAL(signalConfirmButtonClicked()));
    SetValidation();
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
    QString postStr = User::convertPost(user.GetPost());
    ui->Post->setCurrentText(postStr);
    QString statusStr = User::convertStatusToString(user.GetStatus());
    ui->Status->setCurrentText(statusStr);
}

void ChangeUserDataWidget::CheckingFieldsEmpty(){
    if(ui->LastName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле фамилии не может быть пустым.");
    }
    if(ui->FirstName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле имени не может быть пустым.");
    }
    if(ui->Phone->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле телефона не может быть пустым.");
    }
    if(ui->LoginLine->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле логина не может быть пустым.");
    }
    if(ui->PasswordLine->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле пароля не может быть пустым.");
    }
}

void ChangeUserDataWidget::SetValidation(){
    ui->LastName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->FirstName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Patronymic->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));

    ui->Branch->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));
    ui->Address->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));

    ui->LoginLine->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_LOGIN,this));
}

User ChangeUserDataWidget::GetSelectUser(){
    User changeUser = user;
    changeUser.SetLastName(ui->LastName->text());
    changeUser.SetFirstName(ui->FirstName->text());
    changeUser.SetPatronymic(ui->Patronymic->text());
    changeUser.SetPhone(ui->Phone->text());
    changeUser.SetAddress(ui->Address->text());
    int post = User::convertPostToInt(ui->Post->currentText());
    changeUser.SetPost(post);
    int status = User::convertStatusToInt(ui->Status->currentText());
    changeUser.SetStatus(status);
    changeUser.SetBranch(ui->Branch->text());
    changeUser.SetLogin(ui->LoginLine->text());
    changeUser.SetPassword(ui->PasswordLine->text());
    return changeUser;
}
