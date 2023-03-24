#ifndef SET_HOT_H
#define SET_HOT_H

#include <QDialog>
#include "keyboard.h"

namespace Ui {
class Set_hot;
}

class Set_hot : public QDialog
{
    Q_OBJECT
signals:
    void sendData(QString);//信号函数
public:
    explicit Set_hot(QWidget *parent = nullptr);
    ~Set_hot();
private slots:
    void slotKeyBorder_Exec();
    void settext();
    void closeui();
    void sure();
    void send_temp_data();
private:
    Ui::Set_hot *ui;
    KeyBoard *key;
};

#endif // SET_HOT_H
