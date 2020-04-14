/*
File name: mainmenu.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Implementation of the MainMenu class
*/

#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QCoreApplication>
#include <QString>

#include "mainmenu.h"
#include "mainwindow.h"

MainMenu::MainMenu(MainWindow *parent) : QWidget(parent), mainWindow_(parent)
{
    // background image
    QPixmap bkgnd("./resources/background.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled({800,600}, Qt::IgnoreAspectRatio);
    background_ = new QPalette();
    background_->setBrush(QPalette::Background, bkgnd);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setSpacing(15);
    vlayout->setMargin(250);

    // creation of main buttons ie single player, multi player and high scores
    singleP_ = new QPushButton("Jouer");
    howToPlay_ = new QPushButton("Comment jouer");
    quit_ = new QPushButton("Quitter");

    // setting size of buttons
    singleP_->setFixedHeight(35);
    howToPlay_->setFixedHeight(35);
    quit_->setFixedHeight(35);

    // setting button styles
    this->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                        "font-size: 20px; border-radius: 10px;");

    vlayout->addWidget(singleP_);
    vlayout->addWidget(howToPlay_);
    vlayout->addWidget(quit_);

    setLayout(vlayout);

    // connection button signals to slots
    // for single player button
    connect(singleP_, SIGNAL (pressed()), this, SLOT (onClickedPlay()));
    connect(singleP_, SIGNAL (released()), this, SLOT (goToSinglePlayer()));

    // for help button
    connect(howToPlay_, SIGNAL (pressed()), this, SLOT (onClickedHowTo()));
    connect(howToPlay_, SIGNAL (released()), this, SLOT (howTo()));

    // for quit button
    connect(quit_, SIGNAL (pressed()), this, SLOT (onClickedQuit()));
    connect(quit_, SIGNAL (released()), this, SLOT (quitApp()));
}

MainMenu::~MainMenu()
{
    delete singleP_;
    delete howToPlay_;
    delete background_;
    delete quit_;
}

// Function to set the background/display when the player clicks the Play button
void MainMenu::goToSinglePlayer()
{
    SinglePlayer* sp = new SinglePlayer(mainWindow_);
    mainWindow_->setPalette(*sp->getPalette());
    mainWindow_->setCentralWidget(sp);
}

// Function that generates a popup with the game's rules when the player clicks the How to button 
void MainMenu::howTo()
{
    QMessageBox* howToPlayBox = new QMessageBox(this);
    howToPlayBox->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	QString text = QString::fromUtf8("Le jeu commence lorsque vous clickez sur le boutton OK apr\xc3\xa8s avoir entr\xc3\xa9 votre nom.\n"
					"Pour commencer, 3 images vont s'allumer. Vous devez r\xc3\xa9p\xc3\xa9ter la s\xc3\xa9quence. "
					"Une image sera rajout%1e \xc3\xa0 chaque tour.\nLe jeu continue jusqu'\xc3\xa0 ce que vous %1chouez.").arg("\xc3\xa9");

    howToPlayBox->setText(text);
    howToPlayBox->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                                "font-size: 25px; padding-left: 0px; padding-right: 15px;");
    howToPlayBox->exec();
}

// Function to generate the animation when the player clicks the Play button 
void MainMenu::onClickedPlay()
{
    singleP_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                            "font-size: 20px; border-radius: 10px;");
}

// Function to generate the animation when the player clicks the How to button
void MainMenu::onClickedHowTo()
{
    howToPlay_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                              "font-size: 20px; border-radius: 10px;");
    QTimer::singleShot(200, this, SLOT (backDefault()));
}

// Function to generate the animation when the player clicks the Quit button
void MainMenu::onClickedQuit()
{
    quit_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                         "font-size: 20px; border-radius: 10px;");
}

// Function to set the buttons' apperances back to normal (after the player clicked them)
void MainMenu::backDefault()
{
    howToPlay_->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                        "font-size: 20px; border-radius: 10px;");
}

// Function to quit the application (when the player clicks the Quit button)
void MainMenu::quitApp()
{
    QCoreApplication::quit();
}
