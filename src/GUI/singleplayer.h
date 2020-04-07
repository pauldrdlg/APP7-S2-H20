#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPalette>

class SinglePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SinglePlayer(QWidget *parent = nullptr);
     ~SinglePlayer();
    QPalette* getPalette() {return backgroundS_;}

private:
    QPalette* backgroundS_;
};

#endif // SINGLEPLAYER_H
