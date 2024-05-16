#include "abstractuserwindow.h"
#include <QTableView>
#include <QHeaderView>
AbstractUserWindow::AbstractUserWindow(const User& us, QWidget *parent)
    : QMainWindow{parent}
{
    user = us;

    iconSuccessMessage = QIcon(":/images/resources/CheckMarkGreen.png");
    iconUnsuccessMessage = QIcon(":/images/resources/close.png");

    acceptMessageButton->setIcon(QIcon(iconUnsuccessMessage));

    profileButton = new QPushButton;
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);

    profilePanel = new PanelLeftSide(this);
    profilePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    profilePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    profilePanel->init();

    profileWindow = new ProfileWindow(this);
    profilePanel->setPanelSize(profileWindow->size().width()+5);
    profilePanel->setWidgetResizable(true);
    profilePanel->setWidget(profileWindow);
    profileWindow->fillProfile(us);
    int shadowSettings = GetShadowSettings();
    if((shadowSettings == 1)||(shadowSettings == -1)){
        profileWindow->SetShadowCheckBox(true);
    }
    else{
        profileWindow->SetShadowCheckBox(false);
    }

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

    timerClosingMessage = new QTimer(this);
    timerEnableButton = new QTimer(this);
    timerClosingMessage->setSingleShot(true);
    timerEnableButton->setSingleShot(true);

    disableButtonStyleSheet = "font: 500 14pt \"Montserrat Medium\";"
                              "background-color: #c8c8c8;"
                              "color: white;"
                              "border: none;"
                              "font-size: 14px;"
                              "border-radius: 5px;";

    enableButtonStyleSheet ="QPushButton {"
                            "font: 500 14pt \"Montserrat Medium\";"
                            "background-color: #4CAF50;"
                            "color: white;"
                            "border: none;"
                            "font-size: 14px;"
                            "border-radius: 5px;"
                            "}"
                            "QPushButton:hover {"
                            "    background-color: #45a049;"
                            "}"
                            "QPushButton:pressed {"
                            "    background-color: #357a38;"
                            "}";

    AddShadow(profileWindow);

    connect(profileWindow, SIGNAL(signalLogoutButtonClicked()),SIGNAL(signalLogout()));
    connect(profileWindow,SIGNAL(singalCancelButtonClicked()),profileButton, SIGNAL(clicked()));
    connect(profileWindow, SIGNAL(signalShadowCheckBoxStateChanged(int)),SLOT(slotShadowCheckBoxStateChanged(int)));
    connect(profileButton,SIGNAL(clicked()),profilePanel,SLOT(slotStartAnimation()));
    connect(messagePanel,SIGNAL(signalClosingEnd()),SLOT(slotMessageAnimationEnd()));
    connect(timerClosingMessage, &QTimer::timeout, [this]{
        if(messagePanel != nullptr){
            messagePanel->slotStartAnimation();
            MessageFadeOut();
        }
    });
}

AbstractUserWindow::~AbstractUserWindow(){
    qDebug() << "call abstract destructor";
    delete profileButton;
}

User AbstractUserWindow::getUser(){
    return user;
}

void AbstractUserWindow::ShowMessage(QString message, bool typeMessage, QPushButton* button){
    Message msg(message,typeMessage);
    messages.append(msg);
    CheckMessageToShow(button);
}

void AbstractUserWindow::slotMessageAnimationEnd(){
    MessageIsOpening = false;
    CheckMessageToShow();
    emit signalMessageAnimationEnd();
}

void AbstractUserWindow::DisableButton(QPushButton* button){
    button->setEnabled(false);
    button->setStyleSheet(disableButtonStyleSheet);
}

void AbstractUserWindow::EnableButton(QPushButton* button){
    button->setEnabled(true);
    button->setStyleSheet(enableButtonStyleSheet);
}

void AbstractUserWindow::CheckMessageToShow(QPushButton* button){
    if(!messages.empty()){
        if(MessageIsOpening){
            return;
        }

        if(button != nullptr){
            DisableButton(button);
        }

        //emit signalMessageAnimationStart();
        MessageIsOpening = true;
        Message msg = messages.front();
        messages.pop_front();
        lblMessage->setText(msg.message);

        messagePanel->setPanelSize(MessageWidget->size().width()+5);
        messagePanel->SetRect(QRect(0,0,this->rect().width(),60));

        if(msg.typeMessage){
            acceptMessageButton->setIcon(iconSuccessMessage);
        }
        else{
            acceptMessageButton->setIcon(iconUnsuccessMessage);
        }

        messagePanel->slotStartAnimation();
        MessageFadeIn();

        timerClosingMessage->start(2500);
        QMetaObject::Connection connection;
        connection = connect(timerEnableButton, &QTimer::timeout, [this,button,connection]{
            if((messagePanel != nullptr)&&(button != nullptr)){
                EnableButton(button);
            }
            disconnect(connection);
        });
        timerEnableButton->start(3500);
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

void AbstractUserWindow::AddShadow(QObject* obj){
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
        shadowEffects.push_back(shadowEffect);
    }
}

void AbstractUserWindow::SetEnabledGraphicsEffect(bool status){
    for(int i = 0; i < shadowEffects.size(); ++i){
        shadowEffects.at(i)->setEnabled(status);
    }
}

void AbstractUserWindow::SetShadowSettings(int status){
    QSettings settings("MifitSoft","OSOGO");
    settings.setValue("ShadowEffect",status);
    //emit signalShadowSettingsStateChanged(status);
}

int AbstractUserWindow::GetShadowSettings(){
    QSettings settings("MifitSoft", "OSOGO");
    if(settings.contains("ShadowEffect")) {
        int result = settings.value("ShadowEffect").toInt();
        return result;
    }
    return -1;
}

void AbstractUserWindow::ReadAndSetShadowSettings(){
    int ShadowValue = GetShadowSettings();
    if(ShadowValue == -1){
        SetShadowSettings(0);
    }

    if(ShadowValue == 1){
        SetEnabledGraphicsEffect(true);
    }
    else{
        SetEnabledGraphicsEffect(false);
    }
}

void AbstractUserWindow::slotShadowCheckBoxStateChanged(int state){
    if(state == 2){
        SetShadowSettings(1);
        SetEnabledGraphicsEffect(true);
    }
    else{
        SetShadowSettings(0);
        SetEnabledGraphicsEffect(false);
    }
}

void AbstractUserWindow::DefaultSettingView(QTableView* view){
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->horizontalHeader()->setHighlightSections(false);
    view->setColumnHidden(0,true);
}
