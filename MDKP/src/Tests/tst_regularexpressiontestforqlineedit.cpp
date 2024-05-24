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
    void FIO_EXPRESSION_TEST_data();
    void FIO_EXPRESSION_TEST();
    void ADDRESS_EXPRESSION_TEST_data();
    void ADDRESS_EXPRESSION_TEST();
    void LOGIN_EXPRESSION_TEST_data();
    void LOGIN_EXPRESSION_TEST();
    void NUMBER_LINE_EXPRESSION_TEST_data();
    void NUMBER_LINE_EXPRESSION_TEST();
    //void cleanupTestCase();
};

RegularExpressionTestForQLineEdit::RegularExpressionTestForQLineEdit() {}

RegularExpressionTestForQLineEdit::~RegularExpressionTestForQLineEdit() {}

// void RegularExpressionTestForQLineEdit::initTestCase() {}

 //void RegularExpressionTestForQLineEdit::cleanupTestCase() {}

void RegularExpressionTestForQLineEdit::FIO_EXPRESSION_TEST_data(){
    QTest::addColumn<QString>("testString");
    QTest::addColumn<bool>("result");
    QTest::addColumn<QString>("ErrorStr");

    QTest::newRow("number in fio") << "Vasa1" << false << "Проверка на цифры в ФИО провалена.";
    QTest::newRow("big fio") << "sssssssssssssssssssssssssssssssssssssssss" << false << "Проверка на длину ФИО провалена.";
    QTest::newRow("null fio") << "" << false << "Проверка на пустое ФИО провалена.";
    QTest::newRow("correct fio") << "Olgerd Фон Everek-third" << true << "Проверка корректного ФИО провалена.";
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

    QTest::newRow("null address")<<""<<false<<"Проверка на пустой адрес провалена.";
    QTest::newRow("big address")<<"Планета Земля, страна Россия, "
                                  "Красноярский край, г. Красноярск, ул Ленина, "
                                  "д 43, кв 915 подвал на платформе 9/3 четверти, "
                                  "школа магии Хогвартс, палатка Хагрида."<< false <<"Проверка на длину адреса провалена.";
    QTest::newRow("correct address")<<"г. Красноярск, ул. Ленина, д. 517, кв. 777."<<true<<"Проверка корректного адреса провалена.";
    QTest::newRow("incorrect address")<<"+==г. Красноярск, ул. Ленина, д. 517, кв. 777.+=="<<false<<"Проверка некорректного адреса провалена.";
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

void RegularExpressionTestForQLineEdit::LOGIN_EXPRESSION_TEST_data(){
    QTest::addColumn<QString>("testString");
    QTest::addColumn<bool>("result");
    QTest::addColumn<QString>("ErrorString");

    QTest::newRow("null login")<<""<<false<<"Проверка на пустой логин провалена.";
    QTest::newRow("big login")<<"-666-__________VASAN___228__________-666-"<<false<<"Проверка на длину логина провалена.";
    QTest::newRow("correct login")<<"_Petechkin 228_"<<true<<"Проверка корректного логина провалена.";
    QTest::newRow("incorrect login")<<"__=++666DIZEL++=__"<<false<<"Проверка некорректного логина провалена.";
}

void RegularExpressionTestForQLineEdit::LOGIN_EXPRESSION_TEST(){
    QFETCH(QString, testString);
    QFETCH(bool, result);
    QFETCH(QString, ErrorString);

    QRegularExpression addressExp = ValidationConstant::EXP_ON_LOGIN;
    QRegularExpressionMatch match = addressExp.match(testString);
    bool expressionResult = match.hasMatch();
    QVERIFY2(expressionResult == result, qPrintable(ErrorString));
}

void RegularExpressionTestForQLineEdit::NUMBER_LINE_EXPRESSION_TEST_data(){
    QTest::addColumn<QString>("testString");
    QTest::addColumn<bool>("result");
    QTest::addColumn<QString>("ErrorString");

    QTest::newRow("null summa")<<""<<false<<"Проверка на пустую сумму провалена.";
    QTest::newRow("big number")<<"12345678911234.00"<<false<<"Проверка на длину суммы провалена.";
    QTest::newRow("negative number")<<"-324.00"<<false<<"Проверка на отрицательну сумму.";
    QTest::newRow("correct number")<<"517"<<true<<"Проверка корректной суммы.";
}

void RegularExpressionTestForQLineEdit::NUMBER_LINE_EXPRESSION_TEST(){
    QFETCH(QString, testString);
    QFETCH(bool, result);
    QFETCH(QString, ErrorString);

    QRegularExpression addressExp = ValidationConstant::EXP_ON_NUMBER_LINE;
    QRegularExpressionMatch match = addressExp.match(testString);
    bool expressionResult = match.hasMatch();
    QVERIFY2(expressionResult == result, qPrintable(ErrorString));
}

QTEST_APPLESS_MAIN(RegularExpressionTestForQLineEdit)

#include "tst_regularexpressiontestforqlineedit.moc"
