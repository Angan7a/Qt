#include "window.h"
#include <QTextCharFormat>
#include<QDate>
#include<QDebug>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(QObject::tr("Widgety i layouty"));

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    QBoxLayout *topLayout = new QHBoxLayout();
    mainLayout->addLayout(topLayout);
    QBoxLayout *bottomLayout = new QHBoxLayout();
    mainLayout->addLayout(bottomLayout);
    QBoxLayout *leftLayout = new QVBoxLayout();
    topLayout->addLayout(leftLayout);
    QBoxLayout *rightLayout = new QVBoxLayout();
    topLayout->addLayout(rightLayout,1);



    QComboBox *combo = new QComboBox();
    combo->addItem("fizyka");
    combo->addItem("matematyka");
    combo->addItem("chemia");
    QBoxLayout *cbLayout = new QHBoxLayout();
    cbLayout->addWidget(new QLabel(QObject::tr("Kierunek")));
    cbLayout->addWidget(combo);
    leftLayout->addLayout(cbLayout);

    QSpinBox *spinBox = new QSpinBox();
    spinBox->setRange(1,5);
    spinBox->setSuffix(QObject::tr("Rok"));
    QBoxLayout *spinLayout  = new QHBoxLayout();
    spinLayout->addWidget(new QLabel(QObject::tr("Rok studiow")));
    spinLayout->addWidget(spinBox);
    leftLayout->addLayout(spinLayout);

    QGroupBox *gb1 = new QGroupBox(QObject::tr("Sesja"));
    leftLayout->addWidget(gb1);
    QBoxLayout *gb1Layout = new QVBoxLayout(gb1);
    radio_b_1 = new QRadioButton(QObject::tr("letnia"));
    gb1Layout->addWidget(radio_b_1);
    radio_b_2 = new QRadioButton(QObject::tr("zimowa"));
    gb1Layout->addWidget(radio_b_2);
    radio_b_1->setChecked(true);     //set default value (letnia)

    checkBox1 = new QCheckBox(QObject::tr("Dziekanat otwarty"));
    leftLayout->addWidget(checkBox1);

    calendar = new QCalendarWidget();
    leftLayout->addWidget(calendar);
    leftLayout->addStretch(1);
    this->s_letnia(true);       //set default value (letnia)

    QGroupBox *gb2 = new QGroupBox(QObject::tr("Uwagi"));
    rightLayout->addWidget(gb2);
    QBoxLayout *gb2Layout = new QVBoxLayout(gb2);
    QTextEdit *te = new QTextEdit();
    gb2Layout->addWidget(te);

    QPushButton *pb1 = new QPushButton(QObject::tr("OK"));
    QPushButton *pb2 = new QPushButton(QObject::tr("Anuluj"));
    bottomLayout->addWidget(pb1);
    bottomLayout->addWidget(pb2);
    bottomLayout->addStretch(1);
    QPushButton *pb3 = new QPushButton(QObject::tr("Pomoc"));
    bottomLayout->addWidget(pb3);


    QObject::connect(checkBox1,SIGNAL(toggled(bool)),this,SLOT(open_days_dziekanat(bool)));
    QObject::connect(radio_b_1,SIGNAL(toggled(bool)),this,SLOT(s_letnia(bool)));
    QObject::connect(radio_b_2,SIGNAL(toggled(bool)),this,SLOT(s_zimowa(bool)));
    QObject::connect(pb2, SIGNAL(pressed()), this, SLOT(close()));
    QObject::connect(pb1, SIGNAL(pressed()), this, SLOT(push_b_OK()));



}


void Window::open_days_dziekanat(bool show_open_day)
{
    QTextCharFormat format;
    QDate d1(2017, 1, 2);
    QDate d2(2017, 1, 3);
    QDate d3(2017, 1, 4);
    QDate d4(2017, 2, 10);
    QDate d5(2017, 2, 14);
    QDate d6(2017, 2, 24);

    if(show_open_day == true)
    {
        format.setBackground(Qt::gray);

    } else {
        format.setBackground(Qt::white);
    }


    if(radio_b_1->isChecked() == true)
    {
        calendar->setDateTextFormat(d1,format);
        calendar->setDateTextFormat(d2,format);
        calendar->setDateTextFormat(d3,format);

    } else if(radio_b_2->isChecked() == true)
    {
        calendar->setDateTextFormat(d4,format);
        calendar->setDateTextFormat(d5,format);
        calendar->setDateTextFormat(d6,format);

    }


}

void Window::s_letnia(bool czy_letnia)
{

    if( czy_letnia == true)
    {
        QDate d1(2017, 1, 1);
        QDate d2(2017, 1, 10);
        calendar->setDateRange(d1, d2);
    }
    emit open_days_dziekanat(checkBox1->isChecked());

}

void Window::s_zimowa(bool czy_zimowa)
{
    if( czy_zimowa == true)
    {
        QDate d1(2017, 2, 02);
        QDate d2(2017, 2, 25);
        calendar->setDateRange(d1, d2);
    }
    emit open_days_dziekanat(checkBox1->isChecked());
}

void Window::push_b_OK()
{

}




Window::~Window()
{
    delete calendar;
}
