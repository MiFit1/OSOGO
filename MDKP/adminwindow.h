#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "abstractuserwindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public AbstractUserWindow
{
Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
private:
    Ui::AdminWindow *ui;
    void configuringInterface();
};

#endif // ADMINWINDOW_H
