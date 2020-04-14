/*
File name: singleplayer.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for the SinglePlayer class, a class that controls the game 
*/

#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QTimer>
#include <QLabel>
#include <QInputDialog>

#include "gamerinfo.h"
#include "clickablelabel.h"

class SinglePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SinglePlayer(QWidget *parent = nullptr);
     ~SinglePlayer();
    QPalette* getPalette() {return backgroundS_;}

private slots:
	// creates pop up to ask user's name; starts the game
    void start();
	// sets the interval between the flashing images
    void countDown();
	// does animation for the next image to glow
    void update();
	// sets the final image in the sequence to its default state
    void setLastPic();
	// sets next turn
    void nextTurn();
	// check the user's input against the sequence; manages the appropirate popup messages
    void checkAnwsers();

	// functions to add the rat the user clicks on 
    void addRedRat();
    void addBlueRat();
    void addGreenRat();
    void addPurpleRat();

	// functions to manage the Finished button 
    void onClickedFinish();
    void defaultFinish();

	// user input
    void nameEntered();

private:
    QPalette* backgroundS_ = nullptr;
    std::vector<ClickableLabel*> images_;
    std::vector<std::string> glowingImages_= {"./resources/red_glow.png", "./resources/blue_glow.png", "./resources/green_glow.png", "./resources/purple_glow.png"};
    std::vector<std::string> defaultState_ = {"./resources/red.png", "./resources/blue.png", "./resources/green.png", "./resources/purple.png"};
    QTimer* timer_;
    GamerInfo info_;
    QInputDialog* nameInputDialog_;
    unsigned int numberPics_ = 3;     // first round has 3 images to memorize
    int last_;
    QPushButton* doneButton_;
};

#endif // SINGLEPLAYER_H
