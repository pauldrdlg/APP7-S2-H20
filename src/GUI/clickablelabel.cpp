#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
}


ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* ev)
{
    onClicked();
    emit pressed();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    onReleased();
    emit released();
}
