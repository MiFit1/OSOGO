#ifndef RENEGOTIATECONTRACTWINDOW_H
#define RENEGOTIATECONTRACTWINDOW_H

#include <QWidget>

namespace Ui {
class RenegotiateContractWindow;
}

class RenegotiateContractWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenegotiateContractWindow(QWidget *parent = nullptr);
    ~RenegotiateContractWindow();

private:
    Ui::RenegotiateContractWindow *ui;
};

#endif // RENEGOTIATECONTRACTWINDOW_H
