#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QTimer>
#include <QLabel>

#include "gamerinfo.h"
#include "clickablelabel.h"

class SinglePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SinglePlayer(QWidget *parent = nullptr);
     ~SinglePlayer();
    QPalette* getPalette() {return backgroundS_;}

private slots:
    void start();
    void countDown();
    void update();
    void setLastPic();
    void nextTurn();
    void checkAnwsers();

    void testR();
    void testRR();
    void testB();
    void testBB();
    void testG();
    void testGG();
    void testP();
    void testPP();

private:
    QPalette* backgroundS_ = nullptr;
    std::vector<ClickableLabel*> images_;
    std::vector<std::string> glowingImages_= {"./resources/red_glow.png", "./resources/blue_glow.png", "./resources/green_glow.png", "./resources/purple_glow.png"};
    std::vector<std::string> defaultState_ = {"./resources/red.png", "./resources/blue.png", "./resources/green.png", "./resources/purple.png"};
    QTimer* timer_;
    GamerInfo info_;
    unsigned int numberPics_ = 3;     // first round has 3 images to memorize
    int last_;
    QPushButton* doneButton_;
};

#endif // SINGLEPLAYER_H
