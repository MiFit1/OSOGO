#ifndef RENEGOTIATECONTRACTWINDOW_H
#define RENEGOTIATECONTRACTWINDOW_H
#include "contract.h"
#include "client.h"
#include "database.h"
#include "Global.h"
#include "comment.h"
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QListView>
#include <QMessageBox>


namespace Ui {
class RenegotiateContractWindow;
}

class RenegotiateContractWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenegotiateContractWindow(User user,Database* db, QWidget *parent = nullptr);
    ~RenegotiateContractWindow();
    void SetContractAndClient(Contract Contract, Client Client);
    void UpdateAccountantComments();

private:
    Ui::RenegotiateContractWindow *ui;
    Contract contract;
    Client client;
    User user;
    Database* db;

signals:
    void signalBackButtonClicked();
    //void signalRefreshContractAndClient(Contract& contract, Client& client);
    void signalRenegotiateContractDataChanged();
private slots:
    void slotConfirmButtonClicked();
};

#endif // RENEGOTIATECONTRACTWINDOW_H
