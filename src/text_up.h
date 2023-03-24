#ifndef TEXT_UP_H
#define TEXT_UP_H

#include <QTextEdit>
#include <QWidget>
#include <QDialog>
#include <QString>
#include "keyboard.h"

class Text_up : public QTextEdit
{
    Q_OBJECT
public:
    Text_up(QWidget *parent=0);
    ~Text_up(){}
signals:
    void clicked();
public slots:
    void slotClicked();
protected:
    void mousePressEvent(QMouseEvent* event);
private:
    KeyBoard *key;
};

#endif // TEXT_UP_H
