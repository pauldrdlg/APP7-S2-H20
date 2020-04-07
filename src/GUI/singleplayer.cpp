#include <QPixmap>
#include "singleplayer.h"

SinglePlayer::SinglePlayer(QWidget *parent) : QWidget(parent)
{

    // background image
    QPixmap bkgnd("./resources/sp.jpg");                        // watchout for path of image if not found; images in resources folder
    bkgnd = bkgnd.scaled(parent->size(), Qt::IgnoreAspectRatio);
    backgroundS_ = new QPalette();
    backgroundS_->setBrush(QPalette::Background, bkgnd);
}
