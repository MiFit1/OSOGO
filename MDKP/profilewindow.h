#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();

private:
    Ui::ProfileWindow *ui;
signals:
    void signalLogoutButtonClicked();
    void singalCancelButtonClicked();
};

#endif // PROFILEWINDOW_H