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
    explicit ContractConfirmationWindow(User us, Database* db, QWidget *parent = nullptr);
    ~ContractConfirmationWindow();
    void SetContractAndClient(Contract Contract, Client Client);

private:
    Ui::ContractConfirmationWindow *ui;
    Contract contract;
    Client client;
    Database* db;
    User user;
signals:
    void signalBackButtonClicked();
    void signalContractUpdateAndReject();
    void signalContractUpdateAndConfirm();

private slots:
    void slotRejectButtonClicked();
    void slotConfirmButtonClicked();
};

#endif // CONTRACTCONFIRMATIONWINDOW_H
