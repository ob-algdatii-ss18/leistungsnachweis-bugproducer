#ifndef HITDATO5X5_H
#define HITDATO5X5_H

#include <QMainWindow>
#include "PlayGround.h"
#include <QtWidgets/QTextEdit>

class ChooseWindow;

namespace Ui {
class Hidato5x5;
}

class Hidato5x5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hidato5x5(QWidget *parent = 0);
    ~Hidato5x5();

public slots:
    void checkSolution();
    void newGame();
     void back();
private:
    Ui::Hidato5x5 *ui;
    QVector<QTextEdit*> playGroundQTextEdit5x5;
    PlayGround *playground;
    ChooseWindow *mainMenu;
    void initPlayGroundQTextEdit();
    void createNewPlayGround();
};

#endif // HITDATO5X5_H
