#include "renegotiatecontractwindow.h"
#include "ui_renegotiatecontractwindow.h"

RenegotiateContractWindow::RenegotiateContractWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenegotiateContractWindow)
{
    ui->setupUi(this);
    connect(ui->BackButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
}

RenegotiateContractWindow::~RenegotiateContractWindow()
{
    delete ui;
}
