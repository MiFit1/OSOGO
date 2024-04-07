#ifndef CONTRACTCONFIRMATIONWINDOW_H
#define CONTRACTCONFIRMATIONWINDOW_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include "client.h"
#include "contract.h"
#include "Global.h"

namespace Ui {
class ContractConfirmationWindow;
}

class ContractConfirmationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContractConfirmationWindow(QWidget *parent = nullptr);
    ~ContractConfirmationWindow();
    void SetContractAndClient(Contract Contract, Client Client);

private:
    Ui::ContractConfirmationWindow *ui;
    Contract contract;
    Client client;
signals:
    void signalBackButtonClicked();
};

#endif // CONTRACTCONFIRMATIONWINDOW_H
