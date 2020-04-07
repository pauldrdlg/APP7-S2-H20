#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QPalette>
#include <QPushButton>
#include "singleplayer.h"

class MainWindow;
class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(MainWindow *parent = nullptr);
      ~MainMenu();
    QPalette* getPalette() {return background_;}

private slots:
    void goToSinglePlayerMode();

private:

    MainWindow* mainWindow_;
    QPushButton* singleP_;
    QPushButton* multiP_;
    QPushButton* highScore_;
    QPalette* background_;
};

#endif // MAINMENU_H
