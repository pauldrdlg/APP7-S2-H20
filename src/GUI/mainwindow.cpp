/*
File name: mainwindow.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Implementation of the MainWindow class
*/

#include <QPixmap>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // title
    setWindowTitle("TEMPS SAOUL VIENS-TU?");

    // creation of main menu
    mainMenu_ = new MainMenu(this);
    setPalette(*mainMenu_->getPalette());
    setCentralWidget(mainMenu_);
}

MainWindow::~MainWindow()
{
}
