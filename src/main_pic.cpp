#include "main_pic.h"
#include "ui_main_pic.h"
#include <QDateTime>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QFont>
//#include < QPainter>
//#include <QFontMetrics>

QString h;
QString min;
QString s;
int int_h = 0;
int int_min = 0;
int int_s = 0;

QString h1;
QString min1;
QString s1;
int int_h1 = 0;//间隔小时
int int_min1 = 0;//间隔分钟
int int_s1 = 0;//间隔秒
int start_h;//开始小时
int start_min;//开始分钟

Main_pic::Main_pic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_pic)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("智能加热控制系统");
    this->showFullScreen();
    this->resize(1280,800);
    //设置右上角时间
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime_1()));
    timer->start(1000);//1s改变一次

    //加热设置界面
    set_hot = new Set_hot();
    connect(this->ui->P_settemp,SIGNAL(clicked()),this,SLOT(set_hottemp()));

    hand_pic = new Hand_pic();
    connect(ui->P_hand,SIGNAL(clicked()),this,SLOT(hand_pic_function()));

    //模式显示设置
    connect(ui->P_hand,SIGNAL(clicked()),this,SLOT(now_style_hand()));
    connect(ui->P_auto,SIGNAL(clicked()),this,SLOT(now_style_auto()));
    connect(ui->P_normal,SIGNAL(clicked()),this,SLOT(now_style_normal()));

    QTimer *timer1 = new QTimer();
    //PID串口
    port_pid = new Port_PID();
    connect(timer1,SIGNAL(timeout()),this,SLOT(showPort_luwen()));//定时器可复用

    //功率串口
    port_power = new Port_power;
    connect(timer1,SIGNAL(timeout()),this,SLOT(showPort_power_and_watse()));
    timer1->start(3000);//1s改变一次

    //数据展示界面
    data_show = new Data_show();
    connect(ui->P_data_analyse,SIGNAL(clicked()),this,SLOT(show_data_analyse()));

    //时刻设置倒计时
    //connect(hand_pic->set_time->ui->))

    //自学习界面展示
    learn_self = new Learn_self();
    connect(ui->P_start_learn,SIGNAL(clicked()),this,SLOT(show_learn_self()));

    //温度设置
    connect(set_hot,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));

    //时间间隔设置
    connect(hand_pic->set_interval,SIGNAL(sendData_interval(QString,QString)),this,SLOT(receiveData_interval(QString,QString)));
    QTimer *timer_interval = new QTimer();
    connect(timer_interval,SIGNAL(timeout()),this,SLOT(set_interval_hotdata()));
    timer_interval->start(1000);

    //时刻设置
    connect(hand_pic->set_time,SIGNAL(sendData_time(QString,QString)),this,SLOT(receiveData_time(QString,QString)));
    QTimer *timer_time = new QTimer();
    connect(timer_time,SIGNAL(timeout()),this,SLOT(set_time_hotdata()));
    timer_time->start(1000);

    //停止加热功能
    connect(ui->P_stophot,SIGNAL(clicked()),this,SLOT(function_stophot()));
}

Main_pic::~Main_pic()
{
    delete ui;
}

//function:获取当前时间
void Main_pic::showtime_1()
{
    QDateTime *datatime = new QDateTime(QDateTime::currentDateTime());
    QString str = datatime->toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->D_time->setText(str);
}

//function:设置温度界面
void Main_pic::set_hottemp()
{
    //注意setStyleSheet的使用格式
    this->ui->P_settemp->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_15.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->set_hot->exec();
    this->ui->P_settemp->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_5.png)}");
}

//function:手动设置界面
void Main_pic::hand_pic_function()
{
    this->ui->P_hand->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_17.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->hand_pic->exec();
    this->ui->P_hand->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_10.png)}");
}

//function:当前模式显示：手动
void Main_pic::now_style_hand()
{
    ui->D_now_style->setText("   手动模式");
    this->ui->D_now_style->setStyleSheet("QLabel{font: 87 18pt Arial;}");
}

//fucntion:当前模式显示：自动
void Main_pic::now_style_auto()
{
    this->ui->P_auto->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_13.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    ui->D_now_style->setText("   自动模式");
    this->ui->D_now_style->setStyleSheet("QLabel{font: 87 18pt Arial;}");//接字体时直接接入即可，不需要加入样式表中的引号
    this->ui->P_auto->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_3.png)}");
}

//function:当前模式显示：正常
void Main_pic::now_style_normal()
{
    this->ui->P_normal->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_12.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    ui->D_now_style->setText("   正常模式");
    this->ui->D_now_style->setStyleSheet("QLabel{font: 87 18pt Arial;}");
    this->ui->P_normal->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_2.png)}");
}

//funtion:界面显示加热炉温度
void Main_pic::showPort_luwen()
{
    QString str;
    str = port_pid->show_port();
    QFont font1("Arial", 28, 75);
    ui->D_luwen->setText("  "+str);
    ui->D_luwen->setFont(font1);
}

//funtion:界面显示加热炉功率和能耗
void Main_pic::showPort_power_and_watse()
{
    QString str1;
    QString str2;
    str1 = port_power->show_port();
    str2 = port_power->show_port1();
    ui->D_power->setText("   "+str1);
    QFont font("Arial", 28, 75);
    ui->D_nenghao->setFont(font);
    ui->D_power->setFont(font);
    ui->D_nenghao->setText("   "+str2);
    //this->ui->D_nenghao->setStyleSheet("QLabel{font: 87 12pt Arial;}");
}

//function:数据统计界面显示
void Main_pic::show_data_analyse()
{
    this->ui->P_data_analyse->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_14.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->data_show->show();//因为数据统计中类型均为主窗口，没有exec类型，此处需改用show
    this->ui->P_data_analyse->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_1.png)}");
}

//function:自学习界面显示
void Main_pic::show_learn_self()
{
    this->ui->P_start_learn->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_16.png);font: 87 14pt Arial;color: rgb(255, 255, 255);}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->learn_self->show();
    this->ui->P_start_learn->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_9.png);font: 87 14pt Arial;color: rgb(255, 255, 255);}");
}

//将设置的温度转换成PID识别的信息发送，利用port_pid中的属于PID的端口发送出去
void Main_pic::receiveData(QString data)
{
    //将字符转换成数字
    int temp = data.toInt();

    //计算5，6字节
    int num_56 = temp*10;
    //QString str_56_16 = QString::number(num_56,16);
    QString str_56_16 =  QString("%1").arg(num_56,4,16,QLatin1Char('0'));//int转化为16进制，规定长度，前端补零
    //qDebug() << "56:" << str_56_16;

    //计算7，8字节CRC验证码
    int num_78 = 67+temp*10+1;
    //QString str_78_16 = QString::number(num_78,16);//转化16进制，但前端不补0
    QString str_78_16 =  QString("%1").arg(num_78,4,16,QLatin1Char('0'));//int转化为16进制，规定长度，前端补零

    QString ending = "81814300"+str_56_16[2]+str_56_16[3]+str_78_16[0]+str_78_16[1]+str_78_16[2]+str_78_16[3]+str_78_16[0]+str_78_16[1];
    QByteArray hot_temp_num = ending.toLatin1();//将QString转换成QByteArray
    qDebug() << hot_temp_num << " hello";
    const QByteArray hot_readCommand = QByteArrayLiteral("\x81\x81\x43\x00\x20\x03\x64\x03");//80摄氏度写
    //const QByteArray hot_readCommand = QByteArrayLiteral("\x81\x81\x43\x00\xfa\x01\x3e\x01");//25摄氏度写
    this->port_pid->m_serialPort->write(hot_readCommand);
}

//接受时间间隔信息，反应至距离加热时间处
void Main_pic::receiveData_interval(QString data_h,QString data_min)
{
    int_h = data_h.toInt();
    int_min = data_min.toInt();
}

//时间间隔设置距离加热时间
void Main_pic::set_interval_hotdata()
{
    if (int_h != 0 || int_min != 0)
    {
        int_s--;
        if (int_s <= 0)
        {
            int_s = 59;
            int_min --;
            if (int_min == 0)
            {
                int_h--;
            }
        }
        h = QString::number(int_h);
        min = QString::number(int_min);
        s = QString::number(int_s);
        ui->D_hottime->setText("        "+h+" : "+min+" : "+s);

        QFont ft("Microsoft YaHei",18,55);
        ui->D_hottime->setFont(ft);
    }
}

//时刻设置距离加热时间，接受信息
void Main_pic::receiveData_time(QString data_h1,QString data_min1)
{
    start_h = data_h1.toInt();
    start_min = data_min1.toInt();
    QTime *now_time = new QTime(QTime::currentTime());
    int_h1 = start_h-now_time->hour();
    int_min1 = start_min-now_time->minute();
    int_s1 = 60-now_time->second();
    int_min1--;
    if (int_min1 < 0)
    {
        int_min1 += 60;
        int_h1 --;
    }

}

//时刻设置距离加热时间
void Main_pic::set_time_hotdata()
{

    if (int_h1 != 0 || int_min1 != 0)
    {
        int_s1--;
        if (int_s1 <= 0)
        {
            int_s1 = 59;
            int_min1 --;
            if (int_min1 == 0)
            {
                int_h1--;
            }
        }
        h1 = QString::number(int_h1);
        min1 = QString::number(int_min1);
        s1 = QString::number(int_s1);
        ui->D_hottime->setText(h1+" : "+min1+" : "+s1);
    }
}

void Main_pic::function_stophot()
{
    this->ui->P_stophot->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_11.png)}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->P_stophot->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png)}");
    const QByteArray stop_readCommand = QByteArrayLiteral("\x81\x81\x43\x00\xfa\x01\x3e\x01");//25摄氏度写
    this->port_pid->m_serialPort->write(stop_readCommand);
    this->ui->P_stophot->setStyleSheet("QPushButton{border-image: url(:/tubiao/new_4.png)}");
}
