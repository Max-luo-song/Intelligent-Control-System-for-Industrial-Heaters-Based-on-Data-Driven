#include "hand_pic.h"
#include "ui_hand_pic.h"
#include <QTime>

Hand_pic::Hand_pic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hand_pic)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("手动模式");
    connect(ui->P_back,SIGNAL(clicked()),this,SLOT(back()));

    set_time = new Set_time();
    connect(ui->P_settime,SIGNAL(clicked()),this,SLOT(set_time_show()));

    set_interval = new Set_interval();
    connect(ui->P_setinterval,SIGNAL(clicked()),this,SLOT(set_interval_show()));
}

Hand_pic::~Hand_pic()
{
    delete ui;
}

//function:退出当前界面，返回主界面
void Hand_pic::back()
{
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");

}

//function:显示时刻设置界面
void Hand_pic::set_time_show()
{
    this->ui->P_settime->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->set_time->exec();
    this->ui->P_settime->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");

}

//function:显示时间间隔设置界面
void Hand_pic::set_interval_show()
{
    this->ui->P_setinterval->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->set_interval->exec();
    this->ui->P_setinterval->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
}
