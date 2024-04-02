#include "contractconfirmationwindow.h"
#include "ui_contractconfirmationwindow.h"

ContractConfirmationWindow::ContractConfirmationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractConfirmationWindow)
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
