#ifndef TOTAL_WASTE_H
#define TOTAL_WASTE_H

#include <QMainWindow>
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
class Total_waste;
}

class Total_waste : public QMainWindow
{
    Q_OBJECT

public:
    explicit Total_waste(QWidget *parent = nullptr);
    ~Total_waste();

private:
    Ui::Total_waste *ui;
};

#endif // TOTAL_WASTE_H
