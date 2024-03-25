#ifndef ABSTRACTUSERWINDOW_H
#define ABSTRACTUSERWINDOW_H

#include <QMainWindow>

class AbstractUserWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AbstractUserWindow(QWidget *parent = nullptr);

signals:
    void signalLogout();

};

#endif // ABSTRACTUSERWINDOW_H
