#include "clickablelabel.h"

ClickableLabel::ClickableLabel()
{
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent*)
{
    onClicked();
    emit pressed();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent*)
{
    onReleased();
    emit released();
}
