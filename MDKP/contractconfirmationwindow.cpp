#include "contractconfirmationwindow.h"
#include "ui_contractconfirmationwindow.h"

ContractConfirmationWindow::ContractConfirmationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractConfirmationWindow)
{
    ui->setupUi(this);

    AddShadowToChildren(this);
    connect(ui->backButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
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
