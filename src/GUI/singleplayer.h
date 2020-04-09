#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QLabel>

#include "gamerinfo.h"

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

private:
    QPalette* backgroundS_ = nullptr;
    std::vector<QLabel*> images_;
    std::vector<std::string> glowingImages_;
    GamerInfo info_;
};

#endif // SINGLEPLAYER_H
