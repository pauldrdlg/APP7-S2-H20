#include "gamerinfo.h"
#include <time.h>

GamerInfo::GamerInfo()
{
}

GamerInfo::~GamerInfo()
{
}

unsigned int GamerInfo::getNext()
{
    if (iterator_ >= listToMemorize_.size())
    {
        iterator_ = 0;
    }

    return getItem(iterator_++);
}

void GamerInfo::generateListInit()
{
    // generate vector for first turn ie 3 images to memorize
    for (int i = 0; i < 3; i++)
    {
        listToMemorize_.push_back(rand()% 4);
    }
}

void GamerInfo::generateSingle()
{
    listToMemorize_.push_back(rand()% 4);
    iterator_ = 0;
}

bool GamerInfo::checkEnd()
{
    if (iterator_ == listToMemorize_.size())
        return true;
    else
        return false;
}

