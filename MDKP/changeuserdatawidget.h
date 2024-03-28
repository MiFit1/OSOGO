#ifndef CHANGEUSERDATAWIDGET_H
#define CHANGEUSERDATAWIDGET_H

#include <QWidget>

namespace Ui {
class ChangeUserDataWidget;
}

class ChangeUserDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUserDataWidget(QWidget *parent = nullptr);
    ~ChangeUserDataWidget();

private:
    Ui::ChangeUserDataWidget *ui;
};

#endif // CHANGEUSERDATAWIDGET_H
