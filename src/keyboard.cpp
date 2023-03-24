#include "keyboard.h"
#include "ui_keyboard.h"
#include <QTime>

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    this->setWindowTitle("");
    this->edit = nullptr;//初始化把edit清空
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    edit = new QLineEdit();
    connect(this->ui->P_key0, &QPushButton::clicked, this, &KeyBoard::key_0Pressed);
    connect(this->ui->P_key1, &QPushButton::clicked, this, &KeyBoard::key_1Pressed);
    connect(this->ui->P_key2, &QPushButton::clicked, this, &KeyBoard::key_2Pressed);
    connect(this->ui->P_key3, &QPushButton::clicked, this, &KeyBoard::key_3Pressed);
    connect(this->ui->P_key4, &QPushButton::clicked, this, &KeyBoard::key_4Pressed);
    connect(this->ui->P_key5, &QPushButton::clicked, this, &KeyBoard::key_5Pressed);
    connect(this->ui->P_key6, &QPushButton::clicked, this, &KeyBoard::key_6Pressed);
    connect(this->ui->P_key7, &QPushButton::clicked, this, &KeyBoard::key_7Pressed);
    connect(this->ui->P_key8, &QPushButton::clicked, this, &KeyBoard::key_8Pressed);
    connect(this->ui->P_key9, &QPushButton::clicked, this, &KeyBoard::key_9Pressed);
    connect(this->ui->P_dot, &QPushButton::clicked, this, &KeyBoard::key_DotPressed);
    connect(this->ui->P_back, &QPushButton::clicked, this, &KeyBoard::key_BackPressed);
    connect(this->ui->P_sure, &QPushButton::clicked, this, &KeyBoard::key_EnterPressed);
}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::key_0Pressed()
{
    this->ui->P_key0->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "0");
    this->ui->P_key0->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");

}

void KeyBoard::setLineEditObj(QLineEdit* lineEdit)
{
    this->edit = lineEdit;
}

void KeyBoard::key_1Pressed()
{
    this->ui->P_key1->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "1");
    this->ui->P_key1->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_2Pressed()
{
    this->ui->P_key2->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "2");
    this->ui->P_key2->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_3Pressed()
{
    this->ui->P_key3->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "3");
    this->ui->P_key3->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_4Pressed()
{
    this->ui->P_key4->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "4");
    this->ui->P_key4->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_5Pressed()
{
    this->ui->P_key5->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "5");
    this->ui->P_key5->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_6Pressed()
{
    this->ui->P_key6->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "6");
    this->ui->P_key6->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_7Pressed()
{
    this->ui->P_key7->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "7");
    this->ui->P_key7->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_8Pressed()
{
    this->ui->P_key8->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "8");
    this->ui->P_key8->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_9Pressed()
{
    this->ui->P_key9->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + "9");
    this->ui->P_key9->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_DotPressed()
{
    this->ui->P_dot->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text() + ".");
    this->ui->P_dot->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
}

void KeyBoard::key_BackPressed()
{
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 10pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ui->D_lineEdit->setText(this->ui->D_lineEdit->text()
        .left(this->ui->D_lineEdit->text().length() - 1 > 0 ? this->ui->D_lineEdit->text().length() - 1 : 0));
    this->ui->P_back->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 75 15pt Arial;}");

}

void KeyBoard::key_EnterPressed()
{
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/14.png);color: rgb(255, 255, 255);font: 75 15pt Arial;}");
    //使用等待效果，让图标变换有显示
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->edit->setText(this->ui->D_lineEdit->text());
    this->ui->D_lineEdit->clear();
    //this->edit = nullptr;
    this->close();
    this->ui->P_sure->setStyleSheet("QPushButton{border-image: url(:/tubiao/10.png);color: rgb(255, 255, 255);font: 10pt Arial;}");

}
