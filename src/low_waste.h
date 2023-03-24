#ifndef LOW_WASTE_H
#define LOW_WASTE_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QPushButton>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Low_waste;
}

class Low_waste : public QMainWindow
{
    Q_OBJECT

public:
    explicit Low_waste(QWidget *parent = nullptr);
    ~Low_waste();

private:
    Ui::Low_waste *ui;
};

#endif // LOW_WASTE_H
