/*
 * 跨页面传输信号参考博客：https://blog.csdn.net/mrj4124/article/details/103772870
 */
#include "set_hot.h"
#include "ui_set_hot.h"
#include "text_up.h"
#include <QDebug>
#include <QTimer>
#include <QTime>

Set_hot::Set_hot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_hot)
{
    ui->setupUi(this);
    this->setWindowTitle("加热温度设置");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    //设置右上角最大化，最小化，关闭三个按键
    //Qt::WindowFlags flags=Qt::Dialog;
    //flags |=Qt::WindowMinMaxButtonsHint;
    //flags |=Qt::WindowCloseButtonHint;
    //setWindowFlags(flags);
    ui->P_textedit->setAlignment( Qt::AlignVCenter );
    key = new KeyBoard();
    QTimer *timer = new QTimer();
    connect(ui->P_textedit,&Text_up::clicked,this,&Set_hot::slotKeyBorder_Exec);
    connect(timer,SIGNAL(timeout()),this,SLOT(settext()));
    timer->start(15000);
    connect(ui->P_quit,SIGNAL(clicked()),this,SLOT(closeui()));
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(sure()));
    //温度设置信号发送
    connect(ui->P_sure,SIGNAL(clicked()),this,SLOT(send_temp_data()));
}

Set_hot::~Set_hot()
{
    delete ui;
}

void Set_hot::slotKeyBorder_Exec()
{
    this->key->exec();
}

void Set_hot::settext()
{
    ui->P_textedit->setText(this->key->edit->text());
}

void Set_hot::closeui()
{
    this->ui->P_quit->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font:75 18pt Arial}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_quit->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font:75 18pt Arial}");
}

void Set_hot::sure()
{
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font:75 18pt Arial}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    //样式表分割要用分号
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font:75 18pt Arial}");
}

//发出设置温度信号
void Set_hot::send_temp_data()
{
    emit sendData(ui->P_textedit->toPlainText());//获取QtextEdit中数据使用toPlainText函数
}
