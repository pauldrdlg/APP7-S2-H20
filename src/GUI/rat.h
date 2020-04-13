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
