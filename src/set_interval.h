#ifndef SET_INTERVAL_H
#define SET_INTERVAL_H

#include <QDialog>
#include "keyboard.h"
#include <QTimer>
#include "text_up.h"

namespace Ui {
class Set_interval;
}

class Set_interval : public QDialog
{
    Q_OBJECT

private slots:
    void slotKeyBorder_Exec();
    void slotKeyBorder_Exec1();
    void settext();
    void settext1();
    void closeui();
    void sure();
    void send_interval_data();
signals:
    void sendData_interval(QString,QString);//信号函数
public:
    explicit Set_interval(QWidget *parent = nullptr);
    ~Set_interval();

private:
    Ui::Set_interval *ui;
    KeyBoard *key;
    KeyBoard *key1;
};

#endif // SET_INTERVAL_H
