#include "window.h"
#include <QTextCharFormat>
#include<QDate>

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
    QBoxLayout *gb1Layout = new QVBoxLayout(gb1); // ??? QVBoxLayout *gb1Layout = new QVBoxLayout(gb1)
    QRadioButton *rb1 = new QRadioButton(QObject::tr("letnia"));
    gb1Layout->addWidget(rb1);
    QRadioButton *rb2 = new QRadioButton(QObject::tr("zimowa"));
    gb1Layout->addWidget(rb2);

    QCheckBox *checkBox1 = new QCheckBox(QObject::tr("Dziekanat otwarty"));
    leftLayout->addWidget(checkBox1);

    calendar = new QCalendarWidget();
    leftLayout->addWidget(calendar);
    leftLayout->addStretch(1);

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
    QObject::connect(pb2, SIGNAL(pressed()), this, SLOT(close()));



}


void Window::open_days_dziekanat(bool show_open_day)
{
    QDate d1(2017, 1, 12);
    QDate d2(2017, 1, 13);
    QDate d3(2017, 1, 14);
    QTextCharFormat format;

    if(show_open_day == true)
    {
        format.setBackground(Qt::gray);

    } else {
        format.setBackground(Qt::white);
    }
    calendar->setDateTextFormat(d1,format);
    calendar->setDateTextFormat(d2,format);
    calendar->setDateTextFormat(d3,format);

}



Window::~Window()
{

}
