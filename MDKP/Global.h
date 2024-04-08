#ifndef GLOBAL_H
#define GLOBAL_H
#include <QObject>
#include <QGraphicsDropShadowEffect>
#include <QWidget>

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

void AddShadowToChildren(QObject* obj);
#endif // GLOBAL_H
