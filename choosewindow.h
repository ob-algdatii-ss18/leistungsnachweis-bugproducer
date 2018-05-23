#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>
#include "hidato4x4.h"
#include "hidato5x5.h"
#include "hidato6x6.h"

class Hidato4x4;

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = 0);
    ~ChooseWindow();
private slots:
    void startGame4x4();
    void startGame5x5();
    void startGame6x6();


private:
    Ui::ChooseWindow *ui;
    Hidato4x4 hidato4x4;
    Hidato5x5 hidato5x5;
    Hidato6x6 hidato6x6;
};

#endif // CHOOSEWINDOW_H
