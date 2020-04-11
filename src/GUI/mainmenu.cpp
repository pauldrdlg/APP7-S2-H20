#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QCoreApplication>

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
    vlayout->setMargin(220);

    // creation of main buttons ie single player, multi player and high scores
    singleP_ = new QPushButton("Play");
    howToPlay_ = new QPushButton("How to play");
    highScore_ = new QPushButton("High Scores");
    quit_ = new QPushButton("Quit");

    vlayout->addWidget(singleP_);
    vlayout->addWidget(howToPlay_);
    vlayout->addWidget(highScore_);
    vlayout->addWidget(quit_);

    setLayout(vlayout);

    // connection button signals to slots
    // for single player button
    connect(singleP_, SIGNAL (released()), this, SLOT (goToSinglePlayer()));
    // for help button
    connect(howToPlay_, SIGNAL (released()), this, SLOT (howTo()));
    // for quit button
    connect(quit_, SIGNAL (released()), this, SLOT (quitApp()));
}

MainMenu::~MainMenu()
{
    delete singleP_;
    delete howToPlay_;
    delete highScore_;
    delete background_;
}

void MainMenu::goToSinglePlayer()
{
    SinglePlayer* sp = new SinglePlayer(mainWindow_);
    mainWindow_->setPalette(*sp->getPalette());
    mainWindow_->setCentralWidget(sp);
}

void MainMenu::howTo()
{
    QMessageBox* howToPlay = new QMessageBox;
    howToPlay->setWindowTitle("HOW TO PLAY ");
    howToPlay->setText("Enter your name\nOnce you click the OK button, the game starts\nThree images will glow, you must remember the sequence and repeat it to win\nThe games continue until you fail.");
    howToPlay->exec();
}

void MainMenu::quitApp()
{
    QCoreApplication::quit();
}
