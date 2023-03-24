#include "set_time.h"
#include "ui_set_time.h"
#include <QTime>

Set_time::Set_time(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_time)
{
    ui->setupUi(this);
    this->setWindowTitle("加热时刻设置");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    key = new KeyBoard();
    key1 = new KeyBoard();
    QTimer *timer = new QTimer();
    QTimer *timer2 = new QTimer();

    connect(ui->P_textedit,&Text_up::clicked,this,&Set_time::slotKeyBorder_Exec);
    connect(ui->P_textedit1,&Text_up::clicked,this,&Set_time::slotKeyBorder_Exec2);
    connect(timer,SIGNAL(timeout()),this,SLOT(settext()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(settext2()));
    timer->start(1000);
    timer2->start(1000);
    connect(ui->P_quit,SIGNAL(clicked()),this,SLOT(closeui()));
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(sure()));

    //时刻信号发送
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(send_time_data()));
}

Set_time::~Set_time()
{
    delete ui;
}

//function:触发虚拟键盘
void Set_time::slotKeyBorder_Exec()
{
    this->key->exec();
}

void Set_time::slotKeyBorder_Exec2()
{
    this->key1->exec();
}

//function:设置小时文本
void Set_time::settext()
{
    ui->P_textedit->setText(this->key->edit->text());
}

//function:设置分钟文本
void Set_time::settext2()
{
    ui->P_textedit1->setText(this->key1->edit->text());
}

//funtion:关闭当前界面，返回手动设置界面
void Set_time::closeui()
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
void Set_time::sure()
{

    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 75 18pt  Arial;}");
}

//function：发送时刻数据
void Set_time::send_time_data()
{
    //前面是小时数据，后面是分钟数据
    emit sendData_time(ui->P_textedit->toPlainText(),ui->P_textedit1->toPlainText());//获取QtextEdit中数据使用toPlainText函数
}
