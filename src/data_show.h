#ifndef DATA_SHOW_H
#define DATA_SHOW_H

#include <QDialog>
#include "high_waste.h"
#include "low_waste.h"
#include "total_waste.h"
#include "money_waste.h"
#include <QTime>

namespace Ui {
class Data_show;
}

class Data_show : public QDialog
{
    Q_OBJECT

public:
    explicit Data_show(QWidget *parent = nullptr);
    ~Data_show();
private slots:
    void Closeui();
    void show_high_waste();
    void show_low_waste();
    void show_total_waste();
    void show_money_waste();
private:
    Ui::Data_show *ui;
    High_waste *high_waste;
    Low_waste *low_waste;
    Total_waste *total_waste;
    Money_waste *money_waste;
};

#endif // DATA_SHOW_H
