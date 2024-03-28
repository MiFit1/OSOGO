#include "changeuserdatawidget.h"
#include "ui_changeuserdatawidget.h"

ChangeUserDataWidget::ChangeUserDataWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeUserDataWidget)
{
    ui->setupUi(this);
}

ChangeUserDataWidget::~ChangeUserDataWidget()
{
    delete ui;
}
