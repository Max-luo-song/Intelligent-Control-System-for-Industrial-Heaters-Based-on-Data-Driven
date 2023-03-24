#include "text_up.h"

#include <QLabel>
#include <QDialog>
Text_up::Text_up(QWidget* parent):QTextEdit (parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
}

void Text_up::slotClicked()
{

}

void Text_up::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
