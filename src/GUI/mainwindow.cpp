#include <QPushButton>
#include <QPixmap>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // title
    setWindowTitle("TEMPS SAOUL VIENS-TU?");


    // background image
    QPixmap bkgnd("./resources/background.jpg");                        //watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    // main buttons
    QWidget * wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);

    vlay->setSpacing(0);
    vlay->setMargin(250);

    QPushButton *btn1 = new QPushButton("Single Player");
    //btn1->setFixedSize(70, 60);
    vlay->addWidget(btn1);
    QPushButton *btn2 = new QPushButton("Multiplayer");
    vlay->addWidget(btn2);
    QPushButton *btn3 = new QPushButton("High Scores");
    vlay->addWidget(btn3);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);

}

MainWindow::~MainWindow()
{
    delete ui;
}

