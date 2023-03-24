#ifndef PORT_PID_H
#define PORT_PID_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QComboBox>

class Port_PID : public QWidget
{
    Q_OBJECT
public:
    explicit Port_PID(QWidget *parent = nullptr);
    QStringList getPortNameList();//获取所有可用的串口列表
    void openPort();
    QString show_port();
    QSerialPort *m_serialPort;//串口类,为了便于主界面访问，设置为公有
public slots:
    void receiveInfo();
    void sendReadCommand();
private:

    QStringList m_PortNameList;
    QTimer  *timer1;
    QComboBox* m_PortNameComboBox;
    const QByteArray readCommand = QByteArrayLiteral("\x81\x81\x52\x00\x00\x00\x53\x00");//PID读模块
    QString before_data;
};

#endif // PORT_PID_H
