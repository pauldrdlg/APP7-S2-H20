#include <QPixmap>
#include <QGridLayout>
#include <QInputDialog>
#include <time.h>
#include "singleplayer.h"

#include <QDebug>

SinglePlayer::SinglePlayer(QWidget *parent) : QWidget(parent)
{
    // background image
    QPixmap bkgnd("./resources/sp.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled(parent->size(), Qt::IgnoreAspectRatio);
    backgroundS_ = new QPalette();
    backgroundS_->setBrush(QPalette::Background, bkgnd);

    //adding images
    // constructing vector of images
    for(int i = 0; i < 4; i++)
    {
        images_.push_back(new QLabel());
    }

    // adding the default pictures to the vector
    images_[0]->setPixmap(QPixmap("./resources/red.png"));
    images_[1]->setPixmap(QPixmap("./resources/blue.png"));
    images_[2]->setPixmap(QPixmap("./resources/green.png"));
    images_[3]->setPixmap(QPixmap("./resources/purple.png"));

    // adding the default pictures to the layout
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(images_[0], 0, 0, Qt::AlignCenter);       // red rat
    layout->addWidget(images_[1], 1, 0, Qt::AlignCenter);       // blue rat
    layout->addWidget(images_[2], 0, 1, Qt::AlignCenter);       // green rat
    layout->addWidget(images_[3], 1, 1, Qt::AlignCenter);       // purple rat

    layout->setMargin(75);
    setLayout(layout);

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
    // initialization seed
    srand(time(NULL));
    // generate numbers
    int picToChange = rand() % 4;

    // using randomly generated number, select which image is glowing; rest are default status
    last_ = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i == picToChange)
        {
            // setting the pic of the rat to its "glowing" state
            images_[i]->setPixmap(QPixmap(glowingImages_[i].c_str()));
            // adding the image's number to the vector of sequence to memorize (gamer's info)
            info_.setList(picToChange);
            // memorizing the last picture that was selected
            last_ = i;
        }

        else
        {
            // setting the pic of the rat back to normal
            images_[i]->setPixmap(QPixmap(defaultState_[i].c_str()));
        }
    }

    // once get to the number of pics for the current turn (first round is 3 pics, then goes up by one), stop the updating
    if ((info_.getList()).size() >= numberPics_)
    {
        timer_->stop();
        QTimer::singleShot(1500, this, SLOT(setLastPic()));
    }
}

void SinglePlayer::setLastPic()
{
    images_[last_]->setPixmap(QPixmap(defaultState_[last_].c_str()));
}
