#ifndef TARIFFRATEWIDGET_H
#define TARIFFRATEWIDGET_H

#include <QWidget>

namespace Ui {
class TariffRateWidget;
}

class TariffRateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TariffRateWidget(QWidget *parent = nullptr);
    ~TariffRateWidget();
    double GetVehicleInsuranceRate();
    double GetHomePropertyInsuranceRate();
    double GetHealthInsuranceRate();

private:
    Ui::TariffRateWidget *ui;
signals:
    void signalOkButtonClicked();
};

#endif // TARIFFRATEWIDGET_H
