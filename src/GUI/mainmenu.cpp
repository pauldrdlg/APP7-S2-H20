#include <QVBoxLayout>
#include <QPixmap>
#include "mainmenu.h"
#include "mainwindow.h"

MainMenu::MainMenu(MainWindow *parent) : QWidget(parent), mainWindow_(parent)
{
    // background image
    QPixmap bkgnd("./resources/background.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled(parent->size(), Qt::IgnoreAspectRatio);
    background_ = new QPalette();
    background_->setBrush(QPalette::Background, bkgnd);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setSpacing(0);
    vlayout->setMargin(250);

    // creation of main buttons ie single player, multi player and high scores
    singleP_ = new QPushButton("Single Player");
    multiP_ = new QPushButton("Multiplayer");
    highScore_ = new QPushButton("High Scores");

    vlayout->addWidget(singleP_);
    vlayout->addWidget(multiP_);
    vlayout->addWidget(highScore_);

    setLayout(vlayout);

    // connection button signals to slots
    // for single player button
    connect(singleP_, SIGNAL (released()), this, SLOT (goToSinglePlayerMode()));
}

void MainMenu::goToSinglePlayerMode()
{
    SinglePlayer* sp = new SinglePlayer(mainWindow_);
    mainWindow_->setPalette(*sp->getPalette());
    mainWindow_->setCentralWidget(sp);
}
