#include "profilewindow.h"
#include "ui_profilewindow.h"

ProfileWindow::ProfileWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);

    //Эффект тени на дочерние объекты
    for (auto child : this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly)) {
        if (child->metaObject()->className() == QStringLiteral("QLabel")) {
            // Пропускаем QLabel
            continue;
        }
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
        shadowEffect->setBlurRadius(20);
        shadowEffect->setColor(QColor(140,140,140,255));
        shadowEffect->setOffset(3,3);
        child->setGraphicsEffect(shadowEffect);
    }
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
