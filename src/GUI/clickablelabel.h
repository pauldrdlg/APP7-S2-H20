/*
File name: clickablelabel.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for the ClickableLabel class, an abstract class for creating label that will react with mouse events
*/

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel();
    virtual ~ClickableLabel();

signals:
    void pressed();
    void released();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent* ev);

private:
	// different functions for when mouse is pressed and when the mouse button is released
    virtual void onClicked() {}
    virtual void onReleased() {}
};

#endif // CLICKABLELABEL_H
