#include "phoneedit.h"

PhoneEdit::PhoneEdit(QWidget *parent)
    : QLineEdit{parent}
{
    connect(this,SIGNAL(textChanged(QString)),SLOT(slotTextChanged(QString)));
}

void PhoneEdit::mousePressEvent(QMouseEvent *event){
    QLineEdit::mousePressEvent(event);
    if (cursorPosition() < 4)
    {
        setCursorPosition(4);
    }
}
//+7 (924) 667 33
void PhoneEdit::slotTextChanged(QString text){
    int oldPosition = this->cursorPosition();
    static QString oldText;
    QString resultPhone = text;

    static QRegularExpression reg("^\\+7");
    static QRegularExpression regNoDigit("[^\\d]");
    resultPhone.remove(reg);
    resultPhone.remove(regNoDigit);

    if(resultPhone.length() > 0){
        resultPhone.insert(0,"+7 (");
    }
    else{
        oldText = "";
        this->setText("");
        return;
    }

    if(resultPhone.length() > 7){
        resultPhone.insert(7,") ");
    }

    if(resultPhone.length() > 12){
        resultPhone.insert(12,' ');
    }

    if(resultPhone.length() > 15) {
        resultPhone.insert(15,' ');
    }

    this->blockSignals(true);
    this->setText(resultPhone);

    if (oldText.length() >= text.length()) {
        if(oldPosition < 4){
            this->setCursorPosition(4);
        }
        else{
            this->setCursorPosition(oldPosition);
        }
    }

    this->blockSignals(false);
    oldText = text;
}
