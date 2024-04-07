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

void AddShadowToChildren(QObject* obj);
#endif // GLOBAL_H
