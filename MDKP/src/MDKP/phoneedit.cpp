#include "phoneedit.h"

PhoneEdit::PhoneEdit(QWidget *parent)
    : QLineEdit{parent}
{
    connect(this,SIGNAL(textChanged(QString)),SLOT(slotTextChanged(QString)));
}

void PhoneEdit::slotTextChanged(QString text){
    int oldPosition = this->cursorPosition();
    static QString oldText;

    QString resultPhone = text;
    resultPhone.remove(QRegularExpression("[^\\d]"));

    if(resultPhone.length() > 0){
        resultPhone.prepend('+');
    }

    if(resultPhone.length() > 2){
        resultPhone.insert(2," (");
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
        this->setCursorPosition(oldPosition);
    }

    this->blockSignals(false);
    oldText = text;
}
