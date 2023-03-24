#ifndef LEARN_SELF_H
#define LEARN_SELF_H

#include <QMainWindow>
#include <qmath.h>
#include <QtCharts/QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QDebug>
#include <stdio.h>
using namespace QtCharts;

namespace Ui {
class Learn_self;
}

class Learn_self : public QMainWindow
{
    Q_OBJECT

public:
    explicit Learn_self(QWidget *parent = nullptr);
    ~Learn_self();

private:
    Ui::Learn_self *ui;
    void getData();
};

#endif // LEARN_SELF_H
