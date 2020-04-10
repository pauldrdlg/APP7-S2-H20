#include "mainwindow.h"
#include <time.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    // initialization seed
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;



    w.setFixedSize(800, 600);
    w.show();

    return a.exec();
}
