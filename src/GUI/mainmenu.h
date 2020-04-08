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

    MainWindow* mainWindow_ = nullptr;
    QPushButton* singleP_ = nullptr;
    QPushButton* multiP_ = nullptr;
    QPushButton* highScore_ = nullptr;
    QPalette* background_ = nullptr;
};

#endif // MAINMENU_H
