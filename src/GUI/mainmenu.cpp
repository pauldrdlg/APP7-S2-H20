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
    bkgnd = bkgnd.scaled({800,600}, Qt::IgnoreAspectRatio);
    background_ = new QPalette();
    background_->setBrush(QPalette::Background, bkgnd);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    vlayout->setSpacing(15);
    vlayout->setMargin(250);

    // creation of main buttons ie single player, multi player and high scores
    singleP_ = new QPushButton("Play");
    howToPlay_ = new QPushButton("How to play");
    quit_ = new QPushButton("Quit");

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

void MainMenu::onClickedPlay()
{
    singleP_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                        "font-size: 20px; border-radius: 10px;");
}

void MainMenu::onClickedHowTo()
{
    howToPlay_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                              "font-size: 20px; border-radius: 10px;");
    QTimer::singleShot(200, this, SLOT (backDefault()));
}

void MainMenu::onClickedQuit()
{
    quit_->setStyleSheet("background-color: #B7FF64; font-weight: bold; color: black;"
                         "font-size: 20px; border-radius: 10px;");
}

void MainMenu::backDefault()
{
    howToPlay_->setStyleSheet("background-color: #84090c; font-weight: bold; color: white;"
                        "font-size: 20px; border-radius: 10px;");
}

void MainMenu::quitApp()
{
    QCoreApplication::quit();
}
