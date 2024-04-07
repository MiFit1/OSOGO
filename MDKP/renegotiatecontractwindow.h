#ifndef RENEGOTIATECONTRACTWINDOW_H
#define RENEGOTIATECONTRACTWINDOW_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QListView>
#include "contract.h"
#include "client.h"
#include "Global.h"

namespace Ui {
class RenegotiateContractWindow;
}

class RenegotiateContractWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenegotiateContractWindow(QWidget *parent = nullptr);
    ~RenegotiateContractWindow();
    void SetContractAndClient(Contract Contract, Client Client);

private:
    Ui::RenegotiateContractWindow *ui;
signals:
    void signalBackButtonClicked();
};

#endif // RENEGOTIATECONTRACTWINDOW_H
