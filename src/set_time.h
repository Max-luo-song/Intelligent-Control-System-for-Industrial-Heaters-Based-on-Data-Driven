#ifndef SET_TIME_H
#define SET_TIME_H

#include <QDialog>
#include "keyboard.h"
#include <QTimer>
#include "text_up.h"

namespace Ui {
class Set_time;
}

class Set_time : public QDialog
{
    Q_OBJECT

private slots:
    void slotKeyBorder_Exec();
    void slotKeyBorder_Exec2();
    void settext();
    void settext2();
    void closeui();
    void sure();
    void send_time_data();
signals:
    void sendData_time(QString,QString);//信号函数
public:
    explicit Set_time(QWidget *parent = nullptr);
    ~Set_time();
    Ui::Set_time *ui;
private:

    KeyBoard *key;
    KeyBoard *key1;
};

#endif // SET_TIME_H
