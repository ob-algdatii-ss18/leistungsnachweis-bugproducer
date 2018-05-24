#include "choosewindow.h"
#include "ui_choosewindow.h"
#include <QDebug>



ChooseWindow::ChooseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
    connect(ui->button_start_4x4, SIGNAL (clicked()),this,SLOT(startGame4x4()));
    connect(ui->button_start_5x5, SIGNAL (clicked()),this,SLOT(startGame5x5()));
    connect(ui->button_start_6x6, SIGNAL (clicked()),this,SLOT(startGame6x6()));
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}


void ChooseWindow::startGame4x4(){

    hidato4x4.show();
    this->hide();


}

void ChooseWindow::startGame5x5(){

    hidato5x5.show();
    this->hide();


}

void ChooseWindow::startGame6x6(){



    hidato6x6.show();
    this->hide();


}






