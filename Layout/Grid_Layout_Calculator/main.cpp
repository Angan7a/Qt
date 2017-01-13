#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
#include<QGridLayout>
#include<QLCDNumber>
#include<QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget;

    QGridLayout *layout = new QGridLayout(widget);
    QLCDNumber *lcd = new QLCDNumber();


    layout->addWidget(lcd,0,0,1,3);
    QPushButton *pbt[10];

    for (int i=1; i<10; i++)
    {
        pbt[i] = new QPushButton(QString("%1").arg(i));
        layout->addWidget(pbt[i], 1+(i-1)/3, (i-1)%3);
    }
    pbt[0] = new QPushButton(QString("0"));
    layout->addWidget(pbt[0],4,0,1,2);


    widget->show();

    return a.exec();
}
