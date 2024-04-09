#include "tariffratewidget.h"
#include "ui_tariffratewidget.h"

TariffRateWidget::TariffRateWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TariffRateWidget)
{
    ui->setupUi(this);
    connect(ui->okButton,SIGNAL(clicked()),SIGNAL(signalOkButtonClicked()));
}

TariffRateWidget::~TariffRateWidget()
{
    delete ui;
}

double TariffRateWidget::GetVehicleInsuranceRate(){
    return ui->tarrifRate1->value();
}
double TariffRateWidget::GetHomePropertyInsuranceRate(){
    return ui->tarrifRate2->value();
}
double TariffRateWidget::GetHealthInsuranceRate(){
    return ui->tarrifRate3->value();
}
