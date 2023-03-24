#ifndef MONEY_WASTE_H
#define MONEY_WASTE_H

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
class Money_waste;
}

class Money_waste : public QMainWindow
{
    Q_OBJECT

public:
    explicit Money_waste(QWidget *parent = nullptr);
    ~Money_waste();

private:
    Ui::Money_waste *ui;
};

#endif // MONEY_WASTE_H
