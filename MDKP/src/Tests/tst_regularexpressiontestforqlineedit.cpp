#include <QtTest>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include "../MDKP/Global.h"

// add necessary includes here

class RegularExpressionTestForQLineEdit : public QObject
{
    Q_OBJECT

public:
    RegularExpressionTestForQLineEdit();
    ~RegularExpressionTestForQLineEdit();

private slots:
    //void initTestCase();
    //void cleanupTestCase();
    void FIO_EXPRESSION_TEST_data();
    void FIO_EXPRESSION_TEST();
    void ADDRESS_EXPRESSION_TEST_data();
    void ADDRESS_EXPRESSION_TEST();
};

RegularExpressionTestForQLineEdit::RegularExpressionTestForQLineEdit() {}

RegularExpressionTestForQLineEdit::~RegularExpressionTestForQLineEdit() {}

// void RegularExpressionTestForQLineEdit::initTestCase() {}

 //void RegularExpressionTestForQLineEdit::cleanupTestCase() {}

void RegularExpressionTestForQLineEdit::FIO_EXPRESSION_TEST_data(){
    QTest::addColumn<QString>("testString");
    QTest::addColumn<bool>("result");
    QTest::addColumn<QString>("ErrorStr");

    QTest::newRow("number in fio") << "Vasa1" << false << "ФИО не должно содержать цифр.";
    QTest::newRow("big fio") << "sssssssssssssssssssssssssssssssssssssssss" << false << "ФИО не должно быть больше 40 символов.";
    QTest::newRow("null fio") << "" << false << "ФИО не может быть пустым.";
    QTest::newRow("corret fio") << "Olgerd Фон Everek-third" << true << "Имя корректно, но тест провален.";
}

void RegularExpressionTestForQLineEdit::FIO_EXPRESSION_TEST(){
    QFETCH(QString, testString);
    QFETCH(bool, result);
    QFETCH(QString, ErrorStr);
    QRegularExpression fioExp = ValidationConstant::EXP_ON_FIO;
    QRegularExpressionMatch match = fioExp.match(testString);
    bool expressionResult = match.hasMatch();
    QVERIFY2(expressionResult == result, qPrintable(ErrorStr));
}

void RegularExpressionTestForQLineEdit::ADDRESS_EXPRESSION_TEST_data(){
    QTest::addColumn<QString>("testString");
    QTest::addColumn<bool>("result");
    QTest::addColumn<QString>("ErrorString");

    QTest::newRow("null address")<<""<<false<<"Адрес не может быть пустым";
    //QTest::newRow("")
}

void RegularExpressionTestForQLineEdit::ADDRESS_EXPRESSION_TEST(){
    QFETCH(QString, testString);
    QFETCH(bool, result);
    QFETCH(QString, ErrorString);

    QRegularExpression addressExp = ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS;
    QRegularExpressionMatch match = addressExp.match(testString);
    bool expressionResult = match.hasMatch();
    QVERIFY2(expressionResult == result, qPrintable(ErrorString));
}


QTEST_APPLESS_MAIN(RegularExpressionTestForQLineEdit)

#include "tst_regularexpressiontestforqlineedit.moc"
