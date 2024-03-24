#ifndef CONTRACTCONFIRMATIONWINDOW_H
#define CONTRACTCONFIRMATIONWINDOW_H

#include <QWidget>

namespace Ui {
class ContractConfirmationWindow;
}

class ContractConfirmationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContractConfirmationWindow(QWidget *parent = nullptr);
    ~ContractConfirmationWindow();

private:
    Ui::ContractConfirmationWindow *ui;
};

#endif // CONTRACTCONFIRMATIONWINDOW_H
