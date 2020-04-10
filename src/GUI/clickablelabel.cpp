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
    emit pressed();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit released();
}
