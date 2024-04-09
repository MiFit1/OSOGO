#include "contractconfirmationwindow.h"
#include "ui_contractconfirmationwindow.h"

ContractConfirmationWindow::ContractConfirmationWindow(User us, Database* db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractConfirmationWindow)
{
    ui->setupUi(this);
    this->db  = db;
    user = us;
    AddShadowToChildren(this);
    connect(ui->backButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
    connect(ui->RejectButton,SIGNAL(clicked()),SLOT(slotRejectButtonClicked()));
    connect(ui->ConfirmButton,SIGNAL(clicked()),SLOT(slotConfirmButtonClicked()));
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

void ContractConfirmationWindow::slotRejectButtonClicked(){
    Contract changedContract = contract;
    changedContract.SetStatus(2);
    try {
        db->RefreshContractById(changedContract);
        db->AddComment(ui->Comment->toPlainText(),user.GetId(),changedContract.GetId());
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }
    emit signalContractUpdateAndReject();
}

void ContractConfirmationWindow::slotConfirmButtonClicked(){
    Contract changedContract = contract;
    changedContract.SetStatus(3);
    try {
        db->RefreshContractById(changedContract);
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }
    emit signalContractUpdateAndConfirm();
}
