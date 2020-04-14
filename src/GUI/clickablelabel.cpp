/*
File name: clickablelabel.cpp
Author: J. LaFerriere
Date: 14-04-2020
Description: Implementation of the ClickableLabel class
*/

#include "clickablelabel.h"

ClickableLabel::ClickableLabel()
{
}

ClickableLabel::~ClickableLabel()
{
}

// Function to manage action when press mouse button 
void ClickableLabel::mousePressEvent(QMouseEvent*)
{
    onClicked();
    emit pressed();
}

// Function to manage action when mouse button is released
void ClickableLabel::mouseReleaseEvent(QMouseEvent*)
{
    onReleased();
    emit released();
}
