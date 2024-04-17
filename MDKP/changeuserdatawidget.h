#ifndef CHANGEUSERDATAWIDGET_H
#define CHANGEUSERDATAWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class ChangeUserDataWidget;
}

class ChangeUserDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUserDataWidget(QWidget *parent = nullptr);
    ~ChangeUserDataWidget();

    void setUserToChangeWidget(User user);
    void CheckingFieldsEmpty();

private:
    Ui::ChangeUserDataWidget *ui;
    User user;
    void SetValidation();

signals:
    void signalBackButtonCliked();
    void signalRefreshUser(User& user);
private slots:
    void slotConfirmButtonClicked();
};

#endif // CHANGEUSERDATAWIDGET_H
