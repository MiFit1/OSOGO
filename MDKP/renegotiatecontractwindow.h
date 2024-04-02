#ifndef RENEGOTIATECONTRACTWINDOW_H
#define RENEGOTIATECONTRACTWINDOW_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QListView>

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
signals:
    void signalBackButtonClicked();
};

#endif // RENEGOTIATECONTRACTWINDOW_H
