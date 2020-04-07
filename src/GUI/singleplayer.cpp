#include <QPixmap>
#include <QGridLayout>
#include <QLabel>
#include "singleplayer.h"

SinglePlayer::SinglePlayer(QWidget *parent) : QWidget(parent)
{

    // background image
    QPixmap bkgnd("./resources/sp.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled(parent->size(), Qt::IgnoreAspectRatio);
    backgroundS_ = new QPalette();
    backgroundS_->setBrush(QPalette::Background, bkgnd);

    //adding images
    QPixmap blah("./resources/rat.jpg");
    QLabel* m1 = new QLabel();
    m1->setPixmap(blah);

    QLabel* m2 = new QLabel();
    m2->setPixmap(blah);

    QLabel* m3 = new QLabel();
    m3->setPixmap(blah);

    QLabel* m4 = new QLabel();
    m4->setPixmap(blah);

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(m1, 0, 0, Qt::AlignCenter);
    layout->addWidget(m2, 1, 0, Qt::AlignCenter);
    layout->addWidget(m3, 0, 1, Qt::AlignCenter);
    layout->addWidget(m4, 1, 1, Qt::AlignCenter);

    layout->setMargin(75);
    setLayout(layout);
}

SinglePlayer::~SinglePlayer()
{
    delete backgroundS_;
}
