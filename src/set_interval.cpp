#include "set_interval.h"
#include "ui_set_interval.h"
#include <QTime>

Set_interval::Set_interval(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_interval)
{
    ui->setupUi(this);
    this->setWindowTitle("时间间隔设置");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    key = new KeyBoard();
    key1 = new KeyBoard();
    QTimer *timer = new QTimer();
    connect(ui->P_textedit,&Text_up::clicked,this,&Set_interval::slotKeyBorder_Exec);
    connect(ui->P_textedit1,&Text_up::clicked,this,&Set_interval::slotKeyBorder_Exec1);
    connect(timer,SIGNAL(timeout()),this,SLOT(settext()));
    connect(timer,SIGNAL(timeout()),this,SLOT(settext1()));
    timer->start(1000);
    connect(ui->P_quit,SIGNAL(clicked()),this,SLOT(closeui()));
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(sure()));

    //时间间隔信号发送
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(send_interval_data()));
}

Set_interval::~Set_interval()
{
    delete ui;
}

//function:触发虚拟键盘
void Set_interval::slotKeyBorder_Exec()
{
    this->key->exec();
}

//function:触发虚拟键盘
void Set_interval::slotKeyBorder_Exec1()
{
    this->key1->exec();
}

//function:设置文本
void Set_interval::settext()
{
    ui->P_textedit->setText(this->key->edit->text());
}

//function:设置文本
void Set_interval::settext1()
{
    ui->P_textedit1->setText(this->key1->edit->text());
}

//funtion:关闭当前界面，返回手动设置界面
void Set_interval::closeui()
{
    this->ui->P_quit->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_quit->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
}

//function:设置成功，发送串口信号
void Set_interval::sure()
{
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
}

//发送时间间隔设置信号
void Set_interval::send_interval_data()
{
    //前面是小时数据，后面是分钟数据
    emit sendData_interval(ui->P_textedit->toPlainText(),ui->P_textedit1->toPlainText());//获取QtextEdit中数据使用toPlainText函数
}
