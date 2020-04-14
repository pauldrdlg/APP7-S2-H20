/*
File name: gamerinfo.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Implementation of the GamerInfo class
*/

#include "gamerinfo.h"

GamerInfo::GamerInfo()
{
}

GamerInfo::~GamerInfo()
{
}

// Function to get the next item in the list
unsigned int GamerInfo::getNext()
{
    if (iterator_ >= listToMemorize_.size())
    {
        iterator_ = 0;
    }

    return getItem(iterator_++);
}

// Function to generate the initial vector (for the first turn - contains 3 rats to memorize)
void GamerInfo::generateListInit()
{
    // insert first number
    listToMemorize_.push_back(rand() % 4);
    // insert 2 next ones
    generateSingle();
    generateSingle();
}

// Function to add a rat for the next turns
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

// Function to check if iterator is at end of the vector
bool GamerInfo::checkEnd()
{
    if (iterator_ == listToMemorize_.size())
        return true;
    else
        return false;
}

