#include "Global.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QObject>
void AddShadowToChildren(QObject* obj){
    for (auto child : obj->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly)) {
        if (child->metaObject()->className() == QStringLiteral("QLabel")) {
            // Пропускаем QLabel
            continue;
        }
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(child);
        shadowEffect->setBlurRadius(20);
        shadowEffect->setColor(QColor(140,140,140,255));
        shadowEffect->setOffset(3,3);
        child->setGraphicsEffect(shadowEffect);
    }
}

// namespace ValidationConstant {
//     const QRegularExpression EXP_ON_FIO("^[A-Za-zA-Яа-яЁё\\s\\-]{1,40}$");
//     const QRegularExpression EXP_ON_BRANCH_AND_ADDRESS("^[A-Za-zA-Яа-яЁё0-9\\s\\-\\,\\.]{1,100}$");
//     const QRegularExpression EXP_ON_LOGIN("^[A-Za-zA-Яа-яЁё0-9\\s\\-\\_]{1,40}$");
//     const QRegularExpression EXP_ON_NUMBER_LINE("^[0-9]{1,13}\\.{0,1}[0-9]{0,2}$");
// }
