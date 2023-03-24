#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();
    void setLineEditObj(QLineEdit* lineEdit);
    QLineEdit* edit;
private:
    Ui::KeyBoard *ui;
private slots:

    void key_0Pressed();
    void key_1Pressed();
    void key_2Pressed();
    void key_3Pressed();
    void key_4Pressed();
    void key_5Pressed();
    void key_6Pressed();
    void key_7Pressed();
    void key_8Pressed();
    void key_9Pressed();
    void key_DotPressed();
    void key_BackPressed();
    void key_EnterPressed();

};

#endif // KEYBOARD_H
