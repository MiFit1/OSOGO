#ifndef ABSTRACTUSERWINDOW_H
#define ABSTRACTUSERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "profilewindow.h"
#include "QSidePanel/QSidePanel/PanelLeftSide.hpp"
#include "QSidePanel/QSidePanel/PanelRightSide.hpp"
#include "user.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QResizeEvent>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QStackedLayout>
#include <QGraphicsOpacityEffect>
#include <QIcon>
#include <QList>
#include <QSettings>
#include <QTableView>

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
    void signalMessageAnimationStart();
    void signalMessageAnimationEnd();
    //void signalShadowSettingsStateChanged(int state);

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

    void ShowMessage(QString message, bool typeMessage, QPushButton* button = nullptr);
    void AddShadow(QObject* obj);
    void SetEnabledGraphicsEffect(bool status);
    void ReadAndSetShadowSettings();
    void DefaultSettingView(QTableView* view);
private slots:
    void slotMessageAnimationEnd();
    void slotShadowCheckBoxStateChanged(int state);

private:
    bool MessageIsOpening = false;
    QPropertyAnimation* messageFadeEffect;
    QGraphicsOpacityEffect* opacityEffect;
    QStackedLayout* stackedLayout;
    QIcon iconSuccessMessage;
    QIcon iconUnsuccessMessage;
    void MessageFadeIn();
    void MessageFadeOut();
    void DisableButton(QPushButton* button);
    void EnableButton(QPushButton* button);

    QString disableButtonStyleSheet;
    QString enableButtonStyleSheet;

    QTimer* timerClosingMessage;
    QTimer* timerEnableButton;

    QList<QGraphicsDropShadowEffect*> shadowEffects;

    void CheckMessageToShow(QPushButton* button = nullptr);
    void SetShadowSettings(int status);
    int GetShadowSettings();
protected:
    User user;
    void resizeEvent(QResizeEvent* event) override;
};

#endif // ABSTRACTUSERWINDOW_H
