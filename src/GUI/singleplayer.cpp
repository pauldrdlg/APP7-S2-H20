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
    QGridLayout* layout = new QGridLayout();
    doneButton_ = new QPushButton("Finished ");
    layout->addWidget(images_[0], 0, 0, Qt::AlignCenter);       // red rat
    layout->addWidget(images_[1], 1, 0, Qt::AlignCenter);       // blue rat
    layout->addWidget(images_[2], 0, 1, Qt::AlignCenter);       // green rat
    layout->addWidget(images_[3], 1, 1, Qt::AlignCenter);       // purple rat
    layout->addWidget(doneButton_);

    layout->setMargin(75);
    setLayout(layout);

    connect(images_[0], SIGNAL (pressed()), this, SLOT (addRedRat()));
    connect(images_[1], SIGNAL (pressed()), this, SLOT (addBlueRat()));
    connect(images_[2], SIGNAL (pressed()), this, SLOT (addGreenRat()));
    connect(images_[3], SIGNAL (pressed()), this, SLOT (addPurpleRat()));

    connect(doneButton_, SIGNAL (clicked()), this, SLOT (checkAnwsers()));

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
    bool ok;
    QString popUp = QInputDialog::getText(nullptr, "GET READY, HO", "Please enter name : ", QLineEdit::Normal,"", &ok, Qt::MSWindowsFixedSizeDialogHint);
    // recuperate information user put in and store it in name (of Gamer info)
    info_.setName(popUp);

    // when user enters name and presses ok, start game
    if (ok)
    {
        // start game with 3 pictures to memorize
        info_.generateListInit();
        countDown();
    }
}

void SinglePlayer::countDown()
{
    // set time between flashing images (ie which image is next in sequence to memorize)
    timer_= new QTimer;
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
    done.setWindowTitle("DONE");
    done.setText("Your turn - repeat the sequence by clicking the rats.");
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
        info_.generateSingle();
        info_.increaseScore();
        countDown();
    }
   else
    {
        QMessageBox* endGame = new QMessageBox;
        endGame->setWindowTitle("END GAME ");
        QString text = QString("You lose.\nPlay again?\n\nFINAL SCORE: %1").arg(info_.getScore());
        endGame->setText(text);
        endGame->setStandardButtons(QMessageBox::Yes);
        endGame->addButton(QMessageBox::No);
        endGame->setDefaultButton(QMessageBox::No);

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








