#include "port_pid.h"

#include <QDebug>
#include <QLayout>
#include <QByteArray>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QComboBox>
#include <QPushButton>
#include <QTimer>
#include <stdio.h>
#include <QString>
#include <iostream>
using namespace std;

Port_PID::Port_PID(QWidget *parent) : QWidget(parent)
{
    m_serialPort = new QSerialPort;
    m_PortNameList = getPortNameList();
    m_PortNameComboBox = new QComboBox();
    m_PortNameComboBox->addItems(m_PortNameList);

    this->timer1 = new QTimer();

    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
    openPort();
    connect(this->timer1,&QTimer::timeout,this,&Port_PID::sendReadCommand);
    this->timer1->start(3000);//单位是毫秒

}

//function:获取串口列表名称
QStringList Port_PID::getPortNameList()
{
    QStringList m_serialPortName;
    std::string ss;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug() << "serialPortName:" << info.portName();
        ss = info.portName().toStdString();
        cout << ss << endl;
    }
    return m_serialPortName;
}

//fuction:打开串口
void Port_PID::openPort()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }

    //先设置相关数据，再打开串口
    m_serialPort->setPortName(m_PortNameComboBox->currentText());
    m_serialPort->setPortName("/dev/ttyUSB1");
    m_serialPort->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);//设置波特率和读写方向
    m_serialPort->setDataBits(QSerialPort::Data8);//数据位为8位
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//设置无流控制
    m_serialPort->setParity(QSerialPort::NoParity);//无校验位
    m_serialPort->setStopBits(QSerialPort::TwoStop);//两位停止位

    if (m_serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "串口打开成功";
        m_serialPort->setDataTerminalReady(true);//设置控制引脚状态
    }


}

//function:上位机发送读请求数据
void Port_PID::sendReadCommand()
{
    this->m_serialPort->write(this->readCommand);
}

//function:接受数据
void Port_PID::receiveInfo()
{
    QByteArray info;
    QString buf;
    while(m_serialPort->waitForReadyRead(60))
    {
          info += m_serialPort->readAll();
     }
    if (!info.isEmpty())
    {
        before_data = tr(info.toHex());
    }
}

/*
 * QString转char *
 * QByteArray ba = before_data(QString).toLatin1();
 * char *t_b_d = ba.data();
 */
//fucntion:PID模块数值转换，对应加热炉温度
QString Port_PID::show_port()
{
    QByteArray ba = before_data.toLatin1();
    char *t_b_d = ba.data();
    float a[4];
    for (int i=0; i<4; i++)
    {
        if (t_b_d[i]>='0' && t_b_d[i] <= '9')
        {
            a[i] = float(t_b_d[i]-'0');
        }
        else if (t_b_d[i] >= 'a' && t_b_d[i] <= 'f')
        {
            a[i] = float(t_b_d[i])-87;
        }
    }
    float PV;
    PV = (float)(a[0])*16+(float)(a[1])+(float)(a[2])*16*16*16+(float)(a[3])*16*16;
    if (PV > 32767)
        PV = PV - 65536;
    PV /= 10;
    QString s = QString::number(PV);
    return s;
}
