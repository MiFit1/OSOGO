#include "numberedit.h"
#include <QRegularExpression>
#include "Global.h"
#include <QRegularExpressionValidator>

NumberEdit::NumberEdit(QWidget *parent)
    : QLineEdit{parent}
{
    connect(this,SIGNAL(textChanged(QString)),SLOT(slotTextChanged(QString)));
    connect(this,SIGNAL(editingFinished()),SLOT(slotCheckCorrectSumm()));
    this->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_NUMBER_LINE));
}

void NumberEdit::slotTextChanged(QString text){
    QString resultSum = text;
    if(resultSum.contains('.')){
        this->setText(resultSum);
        return;
    }
    else{
        if(resultSum.length() > 13){
            resultSum.insert(13,'.');
            this->setText(resultSum);
        }
    }
}

void NumberEdit::slotCheckCorrectSumm(){
    QString numberStr = this->text();
    if(numberStr.contains('.')){
        static QRegularExpression expressionEndNumber("\\.(\\d{1,2})$");
        QRegularExpressionMatch match = expressionEndNumber.match(numberStr);
        if(match.hasMatch()){
            QString capturedNumbers = match.captured(1);
            if(capturedNumbers.length() == 1)
                numberStr.push_back('0');
        }
        else{
            numberStr.push_back("00");
        }
    }
    else{
        numberStr.push_back(".00");
    }

    this->blockSignals(true);
    this->setText(numberStr);
    this->blockSignals(false);
}
