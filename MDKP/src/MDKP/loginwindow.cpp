#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(Database* database, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    db = database;
    AddShadow(this);
    ReadAndSetShadowSettings();
}


LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginButton_clicked()
{
    User user = db->CheckLogin(ui->LoginLine->text(),ui->PasswordLine->text());
    if(user.isEmpty()){
        QMessageBox::information(this,"Ошибка","Неверно указан логин или пароль");
        return;
    }
    else if(user.GetStatus() == 0){
        QMessageBox::information(this,"Ошибка","К сожалению, вы больше не работаете в нашей компании. Удачи вам на новой работе :D");
        return;
    }
    else{
        emit signalLoginSuccessful(user);
    }
}

void LoginWindow::AddShadow(QObject* obj){
    for (auto child : obj->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly)) {
        if (child->metaObject()->className() == QStringLiteral("QLabel")) {
            continue;
        }
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(child);
        shadowEffect->setBlurRadius(20);
        shadowEffect->setColor(QColor(140,140,140,255));
        shadowEffect->setOffset(3,3);
        child->setGraphicsEffect(shadowEffect);
        shadowEffects.push_back(shadowEffect);
    }
}

void LoginWindow::SetEnabledGraphicsEffect(bool status){
    for(int i = 0; i < shadowEffects.size(); ++i){
        shadowEffects.at(i)->setEnabled(status);
    }
}

void LoginWindow::ReadAndSetShadowSettings(){
    int ShadowValue = GetShadowSettings();
    if((ShadowValue == 1)||(ShadowValue == -1)){
        SetEnabledGraphicsEffect(true);
    }
    else{
        SetEnabledGraphicsEffect(false);
    }
}

int LoginWindow::GetShadowSettings(){
    QSettings settings("MifitSoft", "OSOGO");
    if(settings.contains("ShadowEffect")) {
        int result = settings.value("ShadowEffect").toInt();
        return result;
    }
    return -1;
}
