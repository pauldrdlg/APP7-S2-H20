/*
File name: mainwindo.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for the MainWindow class which generates the main window for the app
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "mainmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainMenu* mainMenu_ = nullptr;

};
#endif // MAINWINDOW_H
