#ifndef HITDATO4X4_H
#define HITDATO4X4_H

#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include "PlayGround.h"

namespace Ui {
class Hidato4x4;
}

class Hidato4x4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hidato4x4(QWidget *parent = 0);
    ~Hidato4x4();
private slots:
    void checkSolution();
    void newGame();
private:
    Ui::Hidato4x4 *ui;
    QVector<QTextEdit*> playGroundQTextEdit4x4;
    PlayGround *playground;
    void initPlayGroundQTextEdit();
    void createNewPlayGround();
};

#endif // HITDATO4X4_H
