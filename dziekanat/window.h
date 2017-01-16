#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include<QBoxLayout>
#include<QComboBox>
#include<QLabel>
#include<QSpinBox>
#include<QGroupBox>
#include<QRadioButton>
#include<QCheckBox>
#include<QCalendarWidget>
#include <QTextEdit>
#include<QPushButton>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private slots:
    void open_days_dziekanat(bool show_open_day);

private:
    QCalendarWidget *calendar;

};

#endif // WINDOW_H
