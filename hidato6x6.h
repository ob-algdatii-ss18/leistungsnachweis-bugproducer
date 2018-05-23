#ifndef HIDATO6X6_H
#define HIDATO6X6_H

#include <QMainWindow>
#include "PlayGround.h"
#include <QtWidgets/QTextEdit>

namespace Ui {
class Hidato6x6;
}

class Hidato6x6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hidato6x6(QWidget *parent = 0);
    ~Hidato6x6();

public slots:
    void checkSolution();
    void newGame();

private:
    Ui::Hidato6x6 *ui;
    QVector<QTextEdit*> playGroundQTextEdit6x6;
    PlayGround *playground;
    void initPlayGroundQTextEdit();
    void createNewPlayGround();

};

#endif // HIDATO6X6_H
