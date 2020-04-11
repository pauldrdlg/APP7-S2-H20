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
    // insert first number
    listToMemorize_.push_back(rand() % 4);
    // insert 2 next ones
    generateSingle();
    generateSingle();
}

void GamerInfo::generateSingle()
{
    int last = listToMemorize_.back();
    int newNbre = rand() % 4;

    // checking for duplicates; if the same as last, will generate new one
    while (newNbre == last)
    {
        newNbre = rand() % 4;
    }

    listToMemorize_.push_back(newNbre);
    iterator_ = 0;
}

bool GamerInfo::checkEnd()
{
    if (iterator_ == listToMemorize_.size())
        return true;
    else
        return false;
}

