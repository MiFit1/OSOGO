#ifndef CHANGEUSERDATAWIDGET_H
#define CHANGEUSERDATAWIDGET_H

#include <QWidget>
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

private:
    Ui::ChangeUserDataWidget *ui;
    User user;
signals:
    void signalBackButtonCliked();
};

#endif // CHANGEUSERDATAWIDGET_H
