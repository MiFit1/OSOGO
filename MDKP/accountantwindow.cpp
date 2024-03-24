#include "accountantwindow.h"
#include "ui_accountantwindow.h"

AccountantWindow::AccountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountantWindow)
{
    ui->setupUi(this);
}

AccountantWindow::~AccountantWindow()
{
    delete ui;
}
