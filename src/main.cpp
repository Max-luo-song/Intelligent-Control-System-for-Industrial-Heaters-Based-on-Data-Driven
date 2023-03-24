#include "main_pic.h"
#include <QApplication>
#include "set_hot.h"
#include "keyboard.h"
#include "hand_pic.h"

int pp = 0;
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    Main_pic w;
    w.show();
    return a.exec();
}
