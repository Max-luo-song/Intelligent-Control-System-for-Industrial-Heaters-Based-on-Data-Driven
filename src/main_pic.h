#ifndef MAIN_PIC_H
#define MAIN_PIC_H

#include <QDialog>
#include <QDateTime>
#include "set_hot.h"
#include "hand_pic.h"
#include "port_pid.h"
#include "port_power.h"
#include "data_show.h"
#include "learn_self.h"

namespace Ui {
class Main_pic;
}

class Main_pic : public QDialog
{
    Q_OBJECT
private slots:
    void showtime_1();//设置时间
    void set_hottemp();//设置温度界面
    void hand_pic_function();//设置手动界面
    void now_style_hand();//手动模式显示
    void now_style_normal();//正常模式显示
    void now_style_auto();//自动模式显示
    void showPort_luwen();//炉温数值显示
    void showPort_power_and_watse();//功率和能耗显示
    void show_data_analyse();//数据统计界面显示
    void show_learn_self();//自学习界面显示
    void receiveData(QString data);//接受设置的温度
    void receiveData_interval(QString data_h,QString data_min);//接受时间间隔设置的距离加热时间
    void set_interval_hotdata();
    void receiveData_time(QString data_h1,QString data_min1);
    void set_time_hotdata();
    void function_stophot(); //停止加热功能
public:
    explicit Main_pic(QWidget *parent = nullptr);
    ~Main_pic();

private:
    Ui::Main_pic *ui;
    Set_hot *set_hot; //设置温度界面
    Hand_pic *hand_pic;//手动设置界面
    Port_PID *port_pid;//PID串口
    Port_power *port_power;//功率串口
    Data_show *data_show;//数据展示界面
    Learn_self *learn_self;//自学习界面
};

#endif // MAIN_PIC_H
