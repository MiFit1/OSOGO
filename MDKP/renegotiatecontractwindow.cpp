#include "renegotiatecontractwindow.h"
#include "ui_renegotiatecontractwindow.h"

RenegotiateContractWindow::RenegotiateContractWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenegotiateContractWindow)
{
    ui->setupUi(this);

    //Тени на дочерние объекты
    AddShadowToChildren(this);
    connect(ui->BackButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
}

RenegotiateContractWindow::~RenegotiateContractWindow()
{
    delete ui;
}

void RenegotiateContractWindow::SetContractAndClient(Contract Contract, Client Client){
    ui->LastName->setText(Client.GetLastName());
    ui->FirstName->setText(Client.GetFirstName());
    ui->Patronymic->setText(Client.GetPatronymic());
    ui->Phone->setText(Client.GetPhone());
    ui->Summa->setText(QString::number(Contract.GetSumma()));
    qDebug()<<Contract.GetTypeInsurance();
    ui->TypeContract->setCurrentText(Contract.GetTypeInsurance());
}
