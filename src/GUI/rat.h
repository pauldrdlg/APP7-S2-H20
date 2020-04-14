/*
File name: rat.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for Rat class, a derived class that inherits from the ClickableLabel class; it controls the glowing/default 
animations for the rat images of the game
*/

#ifndef RAT_H
#define RAT_H

#include "clickablelabel.h"

class Rat : public ClickableLabel
{
public:
    Rat(const std::string& namePicOn, const std::string& namePicOff);

private:
    void onClicked() override;
    void onReleased() override;
    std::string namePicOn_;
    std::string namePicOff_;
};

#endif // RAT_H
