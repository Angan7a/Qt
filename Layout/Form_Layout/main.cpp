#include "mainwindow.h"
#include <QApplication>
#include<QFormLayout>
#include<QLineEdit>
#include<QDateEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *main_widget = new QWidget();

    QFormLayout *layout = new QFormLayout(main_widget);

    QLineEdit *fname = new QLineEdit();
    QLineEdit *sname = new QLineEdit();
    QLineEdit *adress1 = new QLineEdit();
    QLineEdit *adress2 = new QLineEdit();
    QDateEdit *date = new QDateEdit();

    date->setDisplayFormat(QObject::tr("ddd, d MMMM yyyy"));

    layout->addRow(QObject::tr("Imie"), fname);
    layout->addRow(QObject::tr("Nazwisko"), sname);
    layout->addRow(QObject::tr("Adres"), adress1);
    layout->addRow(QObject::tr("Adres"), adress2);
    layout->addRow(QObject::tr("Data urodzenia"), date);

    main_widget->show();

    return a.exec();
}
