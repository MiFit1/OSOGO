#include "contractconfirmationwindow.h"
#include "ui_contractconfirmationwindow.h"

ContractConfirmationWindow::ContractConfirmationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractConfirmationWindow)
{
    ui->setupUi(this);
    AddShadowToChildren(this);
    connect(ui->backButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
    connect(ui->RejectButton,SIGNAL(clicked()),SLOT(slotRejectButtonClicked()));
    connect(ui->ConfirmButton,SIGNAL(clicked()),SIGNAL(signalConfirmButtonClicked()));
    connect(ui->RejectButton,SIGNAL(clicked()),SIGNAL(signalRejectButtonClicked()));
}

ContractConfirmationWindow::~ContractConfirmationWindow()
{
    delete ui;
}

void ContractConfirmationWindow::SetContractAndClient(Contract Contract, Client Client){
    contract = Contract;
    client = Client;
    ui->LastName->setText(client.GetLastName());
    ui->FirstName->setText(client.GetFirstName());
    ui->Patronymic->setText(client.GetPatronymic());
    ui->Phone->setText(client.GetPhone());

    ui->TypeContract->setText(Contract.GetTypeInsurance());
    ui->Summa->setText(Contract.GetSummaString());
}

Contract ContractConfirmationWindow::GetCurrentContract(){
    return contract;
}

QString ContractConfirmationWindow::GetComment(){
    return ui->Comment->toPlainText();
}

void ContractConfirmationWindow::ClearUserData(){
    ui->TypeContract->clear();
    ui->Comment->clear();
    ui->FirstName->clear();
    ui->LastName->clear();
    ui->Summa->clear();
    ui->Patronymic->clear();
    ui->Phone->clear();
}
