#-------------------------------------------------
#
# Project created by QtCreator 2020-10-06T08:30:47
#
#-------------------------------------------------

QT       += core gui
QT += serialport
QT       += core gui sql  charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = system
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        main_pic.cpp \
    set_hot.cpp \
    keyboard.cpp \
    text_up.cpp \
    hand_pic.cpp \
    set_time.cpp \
    set_interval.cpp \
    port_pid.cpp \
    port_power.cpp \
    data_show.cpp \
    learn_self.cpp \
    high_waste.cpp \
    low_waste.cpp \
    total_waste.cpp \
    money_waste.cpp

HEADERS += \
        main_pic.h \
    set_hot.h \
    keyboard.h \
    text_up.h \
    hand_pic.h \
    set_time.h \
    set_interval.h \
    port_pid.h \
    port_power.h \
    data_show.h \
    learn_self.h \
    high_waste.h \
    low_waste.h \
    total_waste.h \
    money_waste.h

FORMS += \
        main_pic.ui \
    set_hot.ui \
    keyboard.ui \
    hand_pic.ui \
    set_time.ui \
    set_interval.ui \
    data_show.ui \
    learn_self.ui \
    high_waste.ui \
    low_waste.ui \
    total_waste.ui \
    money_waste.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
