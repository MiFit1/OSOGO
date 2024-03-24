#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::AdminWindow *ui;
    int currentidx{1};
};

#endif // ADMINWINDOW_H
