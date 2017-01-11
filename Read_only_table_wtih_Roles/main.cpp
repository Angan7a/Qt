#include "dialog.h"
#include <QApplication>
#include<QTableView>
#include"mymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    QTableView tablewiev;
    MyModel myModel(0);
    tablewiev.setModel(&myModel);

    tablewiev.show();

    //w.show();

    return a.exec();
}
