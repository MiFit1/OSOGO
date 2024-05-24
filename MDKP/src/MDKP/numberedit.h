#ifndef NUMBEREDIT_H
#define NUMBEREDIT_H
#include <QLineEdit>
#include <QWidget>

class NumberEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit NumberEdit(QWidget *parent = nullptr);
private:
private slots:
    void slotTextChanged(QString text);
    void slotCheckCorrectSumm();
signals:
};

#endif // NUMBEREDIT_H
