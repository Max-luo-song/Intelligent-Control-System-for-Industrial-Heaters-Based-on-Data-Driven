#ifndef PORT_POWER_H
#define PORT_POWER_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QComboBox>
#include <QDebug>
#include <stdio.h>

class Port_power : public QWidget
{
    Q_OBJECT
public:
    explicit Port_power(QWidget *parent = nullptr);
    QStringList getPortNameList();//获取所有可用的串口列表
    void openPort();
    QString show_port();
    QString show_port1();
public slots:
    void receiveInfo();
    void sendReadCommand();
private:
    QSerialPort *m_serialPort;//串口类
    QStringList m_PortNameList;
    QTimer  *timer1;
    QComboBox* m_PortNameComboBox;
    const QByteArray readCommand = QByteArrayLiteral("\x01\x03\x00\x48\x00\x06\x45\xDE");//功率读模块
    QString before_data;

};

#endif // PORT_POWER_H
