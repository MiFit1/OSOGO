#ifndef PHONEEDIT_H
#define PHONEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QRegularExpression>

class PhoneEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit PhoneEdit(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void slotTextChanged(QString text);
};

#endif // PHONEEDIT_H
