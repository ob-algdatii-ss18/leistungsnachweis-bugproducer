#include "choosewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      ChooseWindow c;
      c.show();


    return a.exec();
}
