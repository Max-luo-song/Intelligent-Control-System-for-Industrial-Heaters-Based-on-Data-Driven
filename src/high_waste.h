#ifndef HIGH_WASTE_H
#define HIGH_WASTE_H

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
class High_waste;
}

class High_waste : public QMainWindow
{
    Q_OBJECT

public:
    explicit High_waste(QWidget *parent = nullptr);
    ~High_waste();

private:
    Ui::High_waste *ui;
};

#endif // HIGH_WASTE_H
