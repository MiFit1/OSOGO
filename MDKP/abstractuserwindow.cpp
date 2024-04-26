#include "abstractuserwindow.h"

AbstractUserWindow::AbstractUserWindow(const User& us, QWidget *parent)
    : QMainWindow{parent}
{
    user = us;

    acceptMessageButton->setIcon(QIcon(":/images/resources/close.png"));

    profileButton = new QPushButton;
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);

    profilePanel = new PanelLeftSide(this);
    profilePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    profilePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
//    profilePanel->SetRect(QRect(10,150,1000,500));
//    profilePanel->SetUseRect();
    profilePanel->init();

    profileWindow = new ProfileWindow(this);
    profilePanel->setPanelSize(profileWindow->size().width()+5);
    profilePanel->setWidgetResizable(true);
    profilePanel->setWidget(profileWindow);
    profileWindow->fillProfile(us);

    acceptMessageButton->setStyleSheet("border: none; min-width: 30px; min-height: 30px; icon-size: 24px;");
    MessageWidget = new QFrame(this);
    MessageWidget->setStyleSheet("background-color: #232323; color: white;");
    lblMessage = new QLabel("Кто-то не установил сообщение)",this);
    lblMessage->setWordWrap(true);
    lblMessage->setFixedWidth(600);
    QHBoxLayout* msgLayout = new QHBoxLayout(MessageWidget);
    msgLayout->addWidget(lblMessage);
    msgLayout->addWidget(acceptMessageButton);
    MessageWidget->setLayout(msgLayout);

    messagePanel = new PanelRightSide(this);
    messagePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    messagePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    messagePanel->init();
    messagePanel->setPanelSize(MessageWidget->size().width());
    messagePanel->setWidgetResizable(true);
    messagePanel->setWidget(MessageWidget);
    messagePanel->SetUseRect();
    messagePanel->hide();

    opacityEffect = new QGraphicsOpacityEffect(this);
    messagePanel->setGraphicsEffect(opacityEffect);

    messageFadeEffect = new QPropertyAnimation(opacityEffect,"opacity");
    messageFadeEffect->setDuration(500);

    connect(profileWindow, SIGNAL(signalLogoutButtonClicked()),SIGNAL(signalLogout()));
    connect(profileWindow,SIGNAL(singalCancelButtonClicked()),profileButton, SIGNAL(clicked()));
    connect(profileButton,SIGNAL(clicked()),profilePanel,SLOT(slotStartAnimation()));
    connect(messagePanel,SIGNAL(signalClosingEnd()),SLOT(slotMessageAnimationEnd()));
}

AbstractUserWindow::~AbstractUserWindow(){
    qDebug() << "call abstract destructor";
    delete profileButton;
}

// void AbstractUserWindow::setUser(const User& us){
//     qDebug()<<us.GetId()<<" setUser metod";
//     user = us;
//     profileWindow->fillProfile(us);
// }

User AbstractUserWindow::getUser(){
    return user;
}

void AbstractUserWindow::ShowMessage(QString message, bool typeMessage){
    Message msg(message,typeMessage);
    messages.append(msg);
    slotCheckMessageToShow();
}

void AbstractUserWindow::slotMessageAnimationEnd(){
    MessageIsOpening = false;
    slotCheckMessageToShow();
}

void AbstractUserWindow::slotCheckMessageToShow(){
    if(!messages.empty()){
        if(MessageIsOpening){
            qDebug()<<"Return";
            return;
        }
        qDebug()<<"Зашёл";
        MessageIsOpening = true;
        Message msg = messages.front();
        messages.pop_front();
        lblMessage->setText(msg.message);

        messagePanel->setPanelSize(MessageWidget->size().width()+5);
        messagePanel->SetRect(QRect(0,0,this->rect().width(),60));
        messagePanel->slotStartAnimation();
        MessageFadeIn();
        //Закрытие сообщения через время
        QTimer::singleShot(2500,[this]{
            messagePanel->slotStartAnimation();
            MessageFadeOut();
        });
    }
}

void AbstractUserWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    messagePanel->SetRect(QRect(-10,0,event->size().width(),60));
}

void AbstractUserWindow::MessageFadeIn(){
    messageFadeEffect->setStartValue(0);
    messageFadeEffect->setEndValue(1);
    messageFadeEffect->start();
}
void AbstractUserWindow::MessageFadeOut(){
    messageFadeEffect->setStartValue(1);
    messageFadeEffect->setEndValue(0);
    messageFadeEffect->start();
}
