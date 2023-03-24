#include "port_power.h"
#include <qmath.h>
#include <QThread>
Port_power::Port_power(QWidget *parent) : QWidget(parent)
{
    m_serialPort = new QSerialPort;
    m_PortNameList = getPortNameList();
    m_PortNameComboBox = new QComboBox();
    m_PortNameComboBox->addItems(m_PortNameList);

    this->timer1 = new QTimer();

    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
    openPort();
    connect(this->timer1,&QTimer::timeout,this,&Port_power::sendReadCommand);
    this->timer1->start(1000);//单位是毫秒
}

//function:获取串口列表名称
QStringList Port_power::getPortNameList()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug() << "serialPortName:" << info.portName();
    }
    return m_serialPortName;
}

//fuction:打开串口
void Port_power::openPort()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }

    //先设置相关数据，再打开串口
    //m_serialPort->setPortName(m_PortNameComboBox->currentText());
    //m_serialPort->setPortName(m_PortNameComboBox->itemText(1));//了解索引情况下使用itemText设置名字
    m_serialPort->setPortName("/dev/ttyUSB0");
    //m_serialPort->setPortName("COM3");//了解名字的情况下可直接使用字符串设置名字
    m_serialPort->setBaudRate(QSerialPort::Baud4800,QSerialPort::AllDirections);//设置波特率和读写方向
    m_serialPort->setDataBits(QSerialPort::Data8);//数据位为8位
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//设置无流控制
    m_serialPort->setParity(QSerialPort::NoParity);//无校验位
    m_serialPort->setStopBits(QSerialPort::TwoStop);//两位停止位

    if (m_serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "串口打开成功1";
        m_serialPort->setDataTerminalReady(true);//设置控制引脚状态
    }


}

//function:上位机发送读请求数据
void Port_power::sendReadCommand()
{
    this->m_serialPort->write(this->readCommand);
}


void Port_power::receiveInfo()
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


//function:接受功率数据
QString Port_power::show_port()
{
    QByteArray ba = before_data.toLatin1();
    char *t_b_d = ba.data();
    QString s;
    QString s_plus;
    float a[4];
    for (int i=0; i<4; i++)
    {
        if (t_b_d[i+15]>='0' && t_b_d[i+15] <= '9')
        {
            a[i] = float(t_b_d[i+15]-'0');
        }
        else if (t_b_d[i+15] >= 'a' && t_b_d[i+15] <= 'f')
        {
            a[i] = float(t_b_d[i+15])-87;
        }
    }
    float PW;
    PW = (float)(a[0])*16*16*16+(float)(a[1])*16*16+(float)(a[2])*16+(float)(a[3]);
    PW = PW/16;
    s = QString::number(PW);

    return s;
}

//function:接受能耗数据
QString Port_power::show_port1()
{
    QByteArray ba = before_data.toLatin1();
    char *t_b_d = ba.data();
    float PWH = 0;
    float a[8];
    for (int i=0; i<8; i++)
    {
        if (t_b_d[i+19]>='0' && t_b_d[i+19] <= '9')
        {
            a[i] = float(t_b_d[i+19]-'0');
        }
        else if (t_b_d[i+19] >= 'a' && t_b_d[i+19] <= 'f')
        {
            a[i] = float(t_b_d[i+19])-87;
        }
    }
    for (int i=0; i<8; i++)
    {
        PWH += (float)(a[7-i])*pow(16,i);
    }
    PWH /= 3200;
    QString s = QString::number(PWH);
    return s;
}
