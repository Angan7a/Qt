#include "window.h"
#include <QTextCharFormat>
#include<QDate>
#include<QDebug>
#include<QMessageBox>
#include<QLineEdit>


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

    QBoxLayout *imie_layout = new QHBoxLayout();
    imie_layout->addWidget(new QLabel(QObject::tr("Imię:        ")));
    imie = new QLineEdit;
    imie_layout->addWidget(imie);
    leftLayout->addLayout(imie_layout);

    QBoxLayout *nazwisko_layout = new QHBoxLayout();
    nazwisko_layout->addWidget(new QLabel(QObject::tr("Nazwisko:")));
    nazwisko = new QLineEdit;
    nazwisko_layout->addWidget(nazwisko);
    leftLayout->addLayout(nazwisko_layout);

    combo = new QComboBox();
    combo->addItem("fizyka");
    combo->addItem("matematyka");
    combo->addItem("chemia");
    QBoxLayout *cbLayout = new QHBoxLayout();
    cbLayout->addWidget(new QLabel(QObject::tr("Kierunek")));
    cbLayout->addWidget(combo);
    leftLayout->addLayout(cbLayout);

    spinBox = new QSpinBox();
    spinBox->setRange(1,5);
    spinBox->setSuffix(QObject::tr(" rok"));
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
    uwagi = new QTextEdit();
    gb2Layout->addWidget(uwagi);

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
    QObject::connect(pb1, SIGNAL(pressed()), this, SLOT(pushed_b_OK()));


    //QObject::connect(this, SIGNAL(pressed_button(QString,QString)), this, SLOT(show_confirmation(QString,QString)));






}


void Window::open_days_dziekanat(bool show_open_day)
{
    QTextCharFormat format, base_format;

    QDate d0(2017, 1, 1);
    QDate d1(2017, 1, 2);
    QDate d2(2017, 1, 3);
    QDate d3(2017, 1, 4);
    QDate d4(2017, 2, 10);
    QDate d5(2017, 2, 14);
    QDate d6(2017, 2, 24);

    base_format = calendar->dateTextFormat(d0);

    if(show_open_day == true)
    {
        format.setBackground(Qt::gray);

    } else {
        format = base_format;
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
    emit open_days_dziekanat(checkBox1->isChecked());   // maybe it is not needed if it is in "s_zimowa"

}

void Window::s_zimowa(bool czy_zimowa)
{
    if( czy_zimowa == true)
    {
        QDate d1(2017, 2, 02);
        QDate d2(2017, 2, 25);
        calendar->setDateRange(d1, d2);
    }
    emit open_days_dziekanat(checkBox1->isChecked());   // maybe it is not needed if it is in "s_letnia"
}

void Window::pushed_b_OK()

{

    QMessageBox mBox;
    mBox.setWindowTitle("Potwierdzenie");
    mBox.setText(QObject::tr("Imię: ") + imie->text() + '\n' +
                 QObject::tr("Nazwisko: ") + nazwisko->text() + '\n' +
                 QObject::tr("Kierunek: ") + combo->currentText() + '\n' +
                 QObject::tr("Rok: ") + QString::number(spinBox->value()) + '\n' +
                 QObject::tr("Data konsultacji: ") + calendar->selectedDate().toString("dd.MM.yyyy") + '\n' +
                 QObject::tr("Uwagi: ") + uwagi->toPlainText() );

    QAbstractButton *p_button_OK = mBox.addButton(QObject::tr("OK"), QMessageBox::NoRole);
    mBox.addButton(QObject::tr("Anuluj"), QMessageBox::YesRole);

    mBox.exec();

    if (mBox.clickedButton() == p_button_OK )
    {
        QMessageBox::information(this,QObject::tr("Potwierdzenie"), QObject::tr("Dziękuję! \nZostałeś dopisany" ));
    }

}





Window::~Window()
{
    delete calendar;
}
