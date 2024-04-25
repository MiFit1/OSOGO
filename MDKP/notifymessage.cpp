#include "notifymessage.h"

NotifyMessage::NotifyMessage(const QString& _message, QWidget* _parent) : QFrame(_parent) {
    setProperty("notifyMessage", true);

    QLabel* message = new QLabel(_message, this);
    message->setProperty("notifyMessage", true);
    message->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    message->setWordWrap(true);
    //QToolButton* close = new QToolButton(this);
    //close->setIcon(QIcon(":/close.png"));

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(message);
    //layout->addWidget(close);

    //QObject::connect(close, &QToolButton::clicked, this, &NotifyMessage::hideMessage);

    setMaximumHeight(0);
    m_lastHeight = 0;

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [=] {
        if (m_lastHeight != maximumHeight()) {
            int delta = maximumHeight() - m_lastHeight;
            m_lastHeight = maximumHeight();
            parentWidget()->resize(parentWidget()->width(), parentWidget()->height() + delta);
            parentWidget()->move(parentWidget()->pos().x(), parentWidget()->pos().y() - delta);
        }
    });
    timer->start(10);
}

void NotifyMessage::showMessage() {
    WAF::Animation::slideIn(this, WAF::FromBottomToTop, false);
    QTimer::singleShot(5000, this, &NotifyMessage::hideMessage);
}

void NotifyMessage::hideMessage() {
    WAF::Animation::slideOut(this, WAF::FromBottomToTop, false);
}
