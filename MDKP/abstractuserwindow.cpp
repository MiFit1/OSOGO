#include "abstractuserwindow.h"

AbstractUserWindow::AbstractUserWindow(QWidget *parent)
    : QMainWindow{parent}
{
    qDebug() << "call abstract constructor";
    profileButton = new QPushButton;
    profileButton->setIcon(QIcon(":/images/resources/settings.png"));
    profileButton->setIconSize(QSize(40, 40));
    profileButton->setMinimumHeight(50);

    profilePanel = new PanelLeftSide(this);
    profilePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    profilePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    profilePanel->init(profileButton);

    profileWindow = new ProfileWindow(this);
    profilePanel->setPanelSize(profileWindow->size().width()+5);
    profilePanel->setWidgetResizable(true);
    profilePanel->setWidget(profileWindow);

    connect(profileWindow, SIGNAL(signalLogoutButtonClicked()),SIGNAL(signalLogout()));
    connect(profileWindow,SIGNAL(singalCancelButtonClicked()),profileButton, SIGNAL(clicked()));
}

AbstractUserWindow::~AbstractUserWindow(){
    qDebug() << "call abstract destructor";
    delete profileButton;
}
