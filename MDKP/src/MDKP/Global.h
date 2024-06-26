#ifndef GLOBAL_H
#define GLOBAL_H
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
    const QRegularExpression EXP_ON_FIO("^[A-Za-zА-Яа-яЁё\\s\\-]{1,40}$");
    const QRegularExpression EXP_ON_BRANCH_AND_ADDRESS("^[A-Za-zА-Яа-яЁё0-9\\s\\-\\,\\.]{1,100}$");
    const QRegularExpression EXP_ON_LOGIN("^[A-Za-zА-Яа-яЁё0-9\\s\\-\\_]{1,40}$");
    const QRegularExpression EXP_ON_NUMBER_LINE("^[0-9]{1,13}\\.{0,1}[0-9]{0,2}$");
}

void AddShadowToChildren(QObject* obj);
#endif // GLOBAL_H
