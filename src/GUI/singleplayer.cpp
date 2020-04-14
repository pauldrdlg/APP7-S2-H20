/*
File name: singleplayer.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Implementation of the SinglePlayer class
*/

#include <QPixmap>
#include <QGridLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QCoreApplication>
#include <time.h>

#include "singleplayer.h"
#include "rat.h"

SinglePlayer::SinglePlayer(QWidget *parent) : QWidget(parent)
{
    // background image
    QPixmap bkgnd("./resources/sp.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled({800,600}, Qt::IgnoreAspectRatio);
    backgroundS_ = new QPalette();
    backgroundS_->setBrush(QPalette::Background, bkgnd);

    //adding images
    // constructing vector of images of default
    for(int i = 0; i < 4; i++)
    {
        images_.push_back(new Rat(glowingImages_[i], defaultState_[i]));
    }

    // adding the default pictures to the layout
    QGridLayout* layout = new QGridLayout(this);
    doneButton_ = new QPushButton("Fini");
    doneButton_->setFixedWidth(250);
    doneButton_->setFixedHeight(70);

    layout->addWidget(images_[0], 0, 0, Qt::AlignCenter);       // red rat
    layout->addWidget(images_[1], 1, 0, Qt::AlignCenter);       // blue rat
    layout->addWidget(images_[2], 0, 1, Qt::AlignCenter);       // green rat
    layout->addWidget(images_[3], 1, 1, Qt::AlignCenter);       // purple rat

    // set style for the finished button
    doneButton_->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                               "font-size: 20px; border-radius: 10px;");

    layout->addWidget(doneButton_, 2, 0, 2, 0, Qt::AlignCenter);
    layout->setMargin(85);
    layout->setSpacing(20);

    setLayout(layout);

    // connecting singals to slots for the 4 rats
    connect(images_[0], SIGNAL (pressed()), this, SLOT (addRedRat()));
    connect(images_[1], SIGNAL (pressed()), this, SLOT (addBlueRat()));
    connect(images_[2], SIGNAL (pressed()), this, SLOT (addGreenRat()));
    connect(images_[3], SIGNAL (pressed()), this, SLOT (addPurpleRat()));

    // connecting the signal for the 'finished' button
    connect(doneButton_, SIGNAL (pressed()), this, SLOT (onClickedFinish()));
    connect(doneButton_, SIGNAL (released()), this, SLOT (checkAnwsers()));

    // timer to create pause before dialog box popup
    QTimer::singleShot(200, this, SLOT(start()));
}

SinglePlayer::~SinglePlayer()
{
    delete backgroundS_;
	
    // deleting vector of images
    for(int i = 0; i < 4; i++)
    {
        delete images_[i];
    }
}

void SinglePlayer::start()
{
    // putting a dialog box for user to inpput name
    nameInputDialog_ = new QInputDialog(this);
    nameInputDialog_->setStyleSheet("background-color: #84090c; font-weight: bold; color: white; font-size: 20px");
    nameInputDialog_->setLabelText("Entrez votre nom ");
    nameInputDialog_->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    layout()->addWidget(nameInputDialog_);
    connect(nameInputDialog_, SIGNAL (accepted()), this, SLOT (nameEntered()));
}

void SinglePlayer::countDown()
{
    // set time between flashing images (ie which image is next in sequence to memorize)
    timer_= new QTimer(this);
    int timerInterval = 1500;     // set at 1.5 seconds
    timer_->start(timerInterval);
    connect(timer_, SIGNAL (timeout()), this, SLOT (update()));
}

void SinglePlayer::update()
{
    // using randomly generated number, select which image is glowing; rest are default status
    last_ = 0;
    for (int i = 0; i < 4; i++)
    {
        // setting the pic of the rat back to normal
        images_[i]->setPixmap(QPixmap(defaultState_[i].c_str()));
    }

    int picToChange = info_.getNext();
    // setting the pic of the rat to its "glowing" state
    images_[picToChange]->setPixmap(QPixmap(glowingImages_[picToChange].c_str()));
    // memorizing the last picture that was selected
    last_ = info_.getList().back();

    // once get to the number of pics for the current turn (first round is 3 pics, then goes up by one), stop the updating
    if (info_.checkEnd())
    {
        timer_->stop();
        QTimer::singleShot(1500, this, SLOT (setLastPic()));
    }
}

void SinglePlayer::setLastPic()
{
    images_[last_]->setPixmap(QPixmap(defaultState_[last_].c_str()));
    numberPics_++;

    QMessageBox done;
    done.setText("C'est votre tour.");
    done.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    done.setStyleSheet("background-color: #84090c; font-weight: bold; color: white; "
                       "font-size: 20px; padding-left: 0px; padding-right: 25px;");
    done.exec();

    // clearing the user anwsers; the user has to re-input the whole sequence from the beginning
    info_.clearUserInput();
}

void SinglePlayer::checkAnwsers()
{
    // when user enters the sequence and presses ok, start game
    // CHECK IF SIZE OK AS WELL
    bool isCorrect = true;
    if (info_.getUser().size() == info_.getList().size())
    {
        for (unsigned int i = 0; i < info_.getUser().size(); i++)
        {
            if (info_.getUserItem(i) != info_.getItem(i))
            {
                isCorrect = false;
            }
        }
    }
    else
    {
        isCorrect = false;
    }

    if (isCorrect)
    {
        QMessageBox* wellDone = new QMessageBox(this);
        wellDone->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        QString text = QString("Parfait, %1").arg(info_.getName());
        wellDone->setText(text);
        wellDone->setStyleSheet("background-color: #84090c; font-weight: bold; color: white; "
                                "font-size: 20px; padding-left: 0px; padding-right: 25px;");
        wellDone->exec();

        info_.generateSingle();
        info_.increaseScore();
        countDown();
    }
   else
    {
        QMessageBox* endGame = new QMessageBox(this);
        endGame->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        QString text = QString("RIP, %1.\nNouvelle partie?\n\nSCORE FINAL: %2").arg(info_.getName()).arg(info_.getScore());
        endGame->setText(text);
        endGame->setStandardButtons(QMessageBox::Yes);
        endGame->addButton(QMessageBox::No);
        endGame->setDefaultButton(QMessageBox::No);
        endGame->setStyleSheet("background-color: #84090c; font-weight: bold; color: white; "
                               "font-size: 20px; padding-left: 0px; padding-right: 25px;");

        if (endGame->exec() == QMessageBox::Yes)
        {
            // restart new game; clear old list and generate new sequence
            info_.clearListMemorize();
            info_.generateListInit();
            countDown();
        }
        else
        {
            QCoreApplication::quit();
        }
    }
}

void SinglePlayer::nextTurn()
{
    for (unsigned int i = 0; i < (info_.getList()).size(); i++)
    {
        // setting the pic of the rat to its "glowing" state
        int pos = info_.getItem(i);
        images_[pos]->setPixmap(QPixmap(glowingImages_[pos].c_str()));
    }
}

void SinglePlayer::addRedRat()
{
    info_.addToListUser(0);
}

void SinglePlayer::addBlueRat()
{
    info_.addToListUser(1);
}

void SinglePlayer::addGreenRat()
{
    info_.addToListUser(2);
}

void SinglePlayer::addPurpleRat()
{
    info_.addToListUser(3);
}

void SinglePlayer::onClickedFinish()
{

    doneButton_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                               "font-size: 20px; border-radius: 10px;");
    QTimer::singleShot(150, this, SLOT (defaultFinish()));
}

void SinglePlayer::defaultFinish()
{
    doneButton_->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                               "font-size: 20px; border-radius: 10px;");
}

void SinglePlayer::nameEntered()
{
    QString text = nameInputDialog_->textValue();
    // retreive information user put in and store it in name (of Gamer info)
    info_.setName(text);

    // when user enters name and presses ok, start game
    info_.generateListInit();
    countDown();
}








