#include "contractconfirmationwindow.h"
#include "ui_contractconfirmationwindow.h"

ContractConfirmationWindow::ContractConfirmationWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractConfirmationWindow)
{
    ui->setupUi(this);
}

ContractConfirmationWindow::~ContractConfirmationWindow()
{
    delete ui;
}
