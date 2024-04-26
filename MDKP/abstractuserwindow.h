#ifndef ABSTRACTUSERWINDOW_H
#define ABSTRACTUSERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "profilewindow.h"
#include "QSidePanel/PanelLeftSide.hpp"
#include "QSidePanel/PanelRightSide.hpp"
#include "user.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QResizeEvent>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QStackedLayout>
#include <QGraphicsOpacityEffect>

class Message
{
public:
    Message(QString msg, bool TypeMessage) {
        message = msg;
        typeMessage = TypeMessage;
    }
    QString message;
    bool typeMessage;
};

class AbstractUserWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AbstractUserWindow(const User& user, QWidget *parent = nullptr);
    ~AbstractUserWindow();

signals:
    void signalLogout();
    void signalToShowMessage();

public:
    QPushButton* profileButton;
    ProfileWindow* profileWindow;
    PanelLeftSide* profilePanel;
    PanelRightSide* messagePanel;
    User getUser();
    QFrame* MessageWidget;
    QLabel* lblMessage;
    QList<Message> messages;
    QToolButton* acceptMessageButton = new QToolButton(this);

    void ShowMessage(QString message, bool typeMessage);
private slots:
    void slotCheckMessageToShow();
    void slotMessageAnimationEnd();

private:
    bool MessageIsOpening = false;
    QPropertyAnimation* messageFadeEffect;
    QGraphicsOpacityEffect* opacityEffect;
    QStackedLayout* stackedLayout;
    void MessageFadeIn();
    void MessageFadeOut();

protected:
    User user;
    void resizeEvent(QResizeEvent* event) override;
};

#endif // ABSTRACTUSERWINDOW_H
