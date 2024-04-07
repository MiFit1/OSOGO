#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    AddShadowToChildren(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_LoginButton_clicked()
{
    if(((ui->PasswordLine->text() == "1")&&(ui->LoginLine->text() == "1"))
        ||((ui->PasswordLine->text() == "2")&&(ui->LoginLine->text() == "2"))
        ||((ui->PasswordLine->text() == "3")&&(ui->LoginLine->text() == "3"))){
        User user(2,ui->LoginLine->text().toInt(),1,"Eliseev","Vasiliy","Andreevich","Киренского 17","87777777777","Super User");
        qDebug()<<user.GetId() << "loginWindow";
        emit signalLoginSuccessful(user);
    }
}

