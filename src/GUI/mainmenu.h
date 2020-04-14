/*
File name: mainmenu.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for the MainMenu class, an class for generating the main menu page of the app
*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QPalette>
#include <QPushButton>
#include "singleplayer.h"

class MainWindow;
class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(MainWindow *parent = nullptr);
      ~MainMenu();
    QPalette* getPalette() {return background_;}

private slots:
    // signals for when click (mainly color changes)
    void onClickedPlay();
    void onClickedHowTo();
    void onClickedQuit();
	// for the color palette 
    void backDefault();

    // signal for when release
    void goToSinglePlayer();
    void quitApp();
    void howTo();

private:
	// needs to point towards a MainWindow object to set the background
    MainWindow* mainWindow_ = nullptr;
	// Play button 
    QPushButton* singleP_ = nullptr;
	// How to play button 
    QPushButton* howToPlay_ = nullptr;
	// Quit button 
    QPushButton* quit_ = nullptr;
    QPalette* background_ = nullptr;
};

#endif // MAINMENU_H
