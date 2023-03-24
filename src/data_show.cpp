#include "data_show.h"
#include "ui_data_show.h"

Data_show::Data_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data_show)
{
    ui->setupUi(this);
    this->setWindowTitle("数据统计");
    //this->setWindowFlags(Qt::WindowStaysOnTopHint);窗口置顶
    connect(ui->P_back,SIGNAL(clicked()),this,SLOT(Closeui()));

    high_waste = new High_waste();
    connect(ui->P_high_waste,SIGNAL(clicked()),this,SLOT(show_high_waste()));

    low_waste = new Low_waste();
    connect(ui->P_low_waste,SIGNAL(clicked()),this,SLOT(show_low_waste()));

    total_waste = new Total_waste();
    connect(ui->P_total_waste,SIGNAL(clicked()),this,SLOT(show_total_waste()));

    money_waste = new Money_waste();
    connect(ui->P_dianfei,SIGNAL(clicked()),this,SLOT(show_money_waste()));
}

Data_show::~Data_show()
{
    delete ui;
}

void Data_show::Closeui()
{
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 14pt 楷体;}");
}

void Data_show::show_high_waste()
{
    this->ui->P_high_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->high_waste->show();
    this->ui->P_high_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
}

void Data_show::show_low_waste()
{
    this->ui->P_low_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->low_waste->show();
    this->ui->P_low_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
}

void Data_show::show_total_waste()
{
    this->ui->P_total_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->total_waste->show();
    this->ui->P_total_waste->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
}

void Data_show::show_money_waste()
{
    this->ui->P_dianfei->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->money_waste->show();
    this->ui->P_dianfei->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 18pt 楷体;}");
}
