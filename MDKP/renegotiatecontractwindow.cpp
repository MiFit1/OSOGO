#include "renegotiatecontractwindow.h"
#include "ui_renegotiatecontractwindow.h"

RenegotiateContractWindow::RenegotiateContractWindow(User user, Database* db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenegotiateContractWindow)
{
    ui->setupUi(this);
    this->db = db;
    this->user = user;
    //Тени на дочерние объекты
    AddShadowToChildren(this);
    connect(ui->BackButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
    connect(ui->SendButton,SIGNAL(clicked()),SLOT(slotConfirmButtonClicked()));
}

RenegotiateContractWindow::~RenegotiateContractWindow()
{
    delete ui;
}

void RenegotiateContractWindow::SetContractAndClient(Contract Contract, Client Client){
    this->contract = Contract;
    this->client = Client;
    ui->LastName->setText(Client.GetLastName());
    ui->FirstName->setText(Client.GetFirstName());
    ui->Patronymic->setText(Client.GetPatronymic());
    ui->Phone->setText(Client.GetPhone());
    ui->Summa->setText(QString::number(Contract.GetSumma()));
    qDebug()<<Contract.GetTypeInsurance();
    ui->TypeContract->setCurrentText(Contract.GetTypeInsurance());
}

void RenegotiateContractWindow::slotConfirmButtonClicked(){
    Client changedClient = client;
    changedClient.SetFirstName(ui->FirstName->text());
    changedClient.SetLastName(ui->LastName->text());
    changedClient.SetPatronymic(ui->Patronymic->text());
    changedClient.SetPhone(ui->Phone->text());

    try {
        db->CheckClientNumberForId(changedClient);
        db->RefreshClientById(changedClient);
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }

    Contract changedContract = contract;
    changedContract.SetSumma(ui->Summa->text().toDouble());
    changedContract.SetTypeInsurance(ui->TypeContract->currentText());
    changedContract.SetIdEmployee(user.GetId());
    changedContract.SetStatus(1);
    try {
        db->RefreshContractById(changedContract);
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }
    emit signalRenegotiateContractDataChanged();
}

