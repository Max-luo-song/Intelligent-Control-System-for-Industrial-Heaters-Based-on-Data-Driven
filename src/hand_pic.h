#ifndef HAND_PIC_H
#define HAND_PIC_H

#include <QDialog>
#include "set_time.h"
#include "set_interval.h"

namespace Ui {
class Hand_pic;
}

class Hand_pic : public QDialog
{
    Q_OBJECT

private slots:
    void back();//退出当前界面，返回主界面
    void set_time_show();//显示时刻设置界面
    void set_interval_show();//显示时间间隔设置界面
public:
    explicit Hand_pic(QWidget *parent = nullptr);
    ~Hand_pic();

public:
    Set_time *set_time;
    Set_interval *set_interval;
private:
    Ui::Hand_pic *ui;

};

#endif // HAND_PIC_H
