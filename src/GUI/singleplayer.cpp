#include <QPixmap>
#include <QGridLayout>
#include <QTimer>
#include <time.h>
#include "singleplayer.h"

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

    // adding the pictures to the vector
    images_[0]->setPixmap(QPixmap("./resources/red.png"));
    images_[1]->setPixmap(QPixmap("./resources/blue.png"));
    images_[2]->setPixmap(QPixmap("./resources/green.png"));
    images_[3]->setPixmap(QPixmap("./resources/purple.png"));

    // adding pictures to the layout
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(images_[0], 0, 0, Qt::AlignCenter);
    layout->addWidget(images_[1], 1, 0, Qt::AlignCenter);
    layout->addWidget(images_[2], 0, 1, Qt::AlignCenter);
    layout->addWidget(images_[3], 1, 1, Qt::AlignCenter);

    layout->setMargin(75);
    setLayout(layout);

    // adding the glowing pictures titles to the vector
    glowingImages_ = {"./resources/red_glow.png", "./resources/blue_glow.png", "./resources/green_glow.png", "./resources/purple_glow.png"};

    // timer to show which is the next image in the sequence to memorize
    QTimer* timer = new QTimer;
    int timerInterval = 1000;
    timer->start(timerInterval);
    connect(timer, SIGNAL (timeout()), this, SLOT (update()));
}

SinglePlayer::~SinglePlayer()
{
    delete backgroundS_;
}

void SinglePlayer::update()
{
    std::vector<std::string> defaultState = {"./resources/red.png", "./resources/blue.png", "./resources/green.png", "./resources/purple.png"};
    // initialization seed
    srand(time(NULL));
    // generate numbers
    int picToChange = rand() % 4;

    for (int i = 0; i < 4; i++)
    {
        if (i == picToChange)
        {
            images_[i]->setPixmap(QPixmap(glowingImages_[i].c_str()));
        }
        else
        {
            images_[i]->setPixmap(QPixmap(defaultState[i].c_str()));
        }
    }
}
