/*
File name: main.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Main file for the App
*/

#include "mainwindow.h"
#include <time.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    // initialization seed
    srand(time(NULL));

    QApplication app(argc, argv);
    MainWindow window;

    window.setFixedSize(800, 600);
    window.show();

    return app.exec();
}
