#ifndef GLOBAL_H
#define GLOBAL_H
#include <QObject>
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QRegularExpression>

enum {
    Unknown = -1,
    Admin = 1,
    Accountant = 2,
    Agent = 3
};

enum {
    UnknownStatus = -1,
    Fired = 0,
    Works = 1
};

namespace ValidationConstant {
    const QRegularExpression EXP_ON_FIO("[A-zA-яЁё\\s\\-]*");
    const QRegularExpression EXP_ON_BRANCH_AND_ADDRESS("[A-zA-яЁё0-9\\s\\-\\,\\.]*");
    const QRegularExpression EXP_ON_LOGIN("[A-zA-я0-9\\s\\-\\_\\.]*");
    const QRegularExpression EXP_ON_NUMBER_LINE("[0-9]{1,13}\\.[0-9]{1,2}");
}

void AddShadowToChildren(QObject* obj);
#endif // GLOBAL_H
