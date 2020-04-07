#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QPalette>
#include <QPushButton>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);
    QPalette* getPalette() {return background_;}

private slots:
    void doSomething();

private:

    QPushButton *singleP_;
    QPushButton *multiP_;
    QPushButton *highScore_;
    QPalette *background_;
};

#endif // MAINMENU_H
