#include "renegotiatecontractwindow.h"
#include "ui_renegotiatecontractwindow.h"

RenegotiateContractWindow::RenegotiateContractWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenegotiateContractWindow)
{
    ui->setupUi(this);

    //Тени на дочерние объекты
    for (auto child : this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly)) {
        if (child->metaObject()->className() == QStringLiteral("QLabel")) {
            // Пропускаем QLabel
            continue;
        }
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
        shadowEffect->setBlurRadius(20);
        shadowEffect->setColor(QColor(140,140,140,255));
        shadowEffect->setOffset(3,3);
        child->setGraphicsEffect(shadowEffect);
    }
    connect(ui->BackButton, SIGNAL(clicked()),SIGNAL(signalBackButtonClicked()));
}

RenegotiateContractWindow::~RenegotiateContractWindow()
{
    delete ui;
}
