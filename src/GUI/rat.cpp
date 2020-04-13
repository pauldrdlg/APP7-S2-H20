#include "rat.h"

Rat::Rat(const std::string &namePicOn, const std::string &namePicOff): namePicOn_(namePicOn), namePicOff_(namePicOff)
{
    setPixmap(QPixmap(namePicOff_.c_str()));
}

void Rat::onClicked()
{
    setPixmap(QPixmap(namePicOn_.c_str()));
}

void Rat::onReleased()
{
    setPixmap(QPixmap(namePicOff_.c_str()));
}
