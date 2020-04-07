#include <QPixmap>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // title
    setWindowTitle("TEMPS SAOUL VIENS-TU?");

    // creation of main menu
    mainMenu_ = new MainMenu(this);
    setPalette(*mainMenu_->getPalette());
    setCentralWidget(mainMenu_);

}

MainWindow::~MainWindow()
{
    delete ui;
}
