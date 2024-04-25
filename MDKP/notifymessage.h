#ifndef NOTIFYMESSAGE_H
#define NOTIFYMESSAGE_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QTimer>
#include "WidgetAnimationFramework/src/Animation/Animation.h"

class NotifyMessage : public QFrame
{
public:
    explicit NotifyMessage(const QString& _message, QWidget* _parent = 0);

    void showMessage();
    void hideMessage();

private:
    int m_lastHeight;
};

#endif // NOTIFYMESSAGE_H
