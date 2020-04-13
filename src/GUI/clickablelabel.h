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
    ~ClickableLabel();

signals:
    void pressed();
    void released();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent* ev);

private:
    virtual void onClicked() {}
    virtual void onReleased() {}
};

#endif // CLICKABLELABEL_H
