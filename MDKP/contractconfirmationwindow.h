#ifndef CONTRACTCONFIRMATIONWINDOW_H
#define CONTRACTCONFIRMATIONWINDOW_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "client.h"
#include "contract.h"
#include "Global.h"
#include "database.h"

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
    Contract GetCurrentContract();
    QString GetComment();
    void ClearUserData();
    QPushButton* GetConfirmButton();
    QPushButton* GetRejcetButton();

private:
    Ui::ContractConfirmationWindow *ui;
    Contract contract;
    Client client;
signals:
    void signalBackButtonClicked();
    void signalConfirmButtonClicked();
    void signalRejectButtonClicked();
};

#endif // CONTRACTCONFIRMATIONWINDOW_H
