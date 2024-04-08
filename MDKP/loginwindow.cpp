#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(Database* database, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    db = database;
    AddShadowToChildren(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_LoginButton_clicked()
{
    User user = db->CheckLogin(ui->LoginLine->text(),ui->PasswordLine->text());
    if(user.isEmpty()){
        return;
    }
    else{
        emit signalLoginSuccessful(user);
    }
}

