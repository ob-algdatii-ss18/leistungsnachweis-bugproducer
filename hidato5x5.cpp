#include "hidato5x5.h"
#include "ui_hidato5x5.h"
#include <QDebug>


#include "choosewindow.h"

Hidato5x5::Hidato5x5(QWidget *parent) :
    QMainWindow(parent),
     playground(new PlayGround(5,-1)),
    ui(new Ui::Hidato5x5)
{
    ui->setupUi(this);
    connect(ui->button_check, SIGNAL (clicked()),this,SLOT(checkSolution()));
    connect(ui->button_new, SIGNAL (clicked()),this,SLOT(newGame()));
    connect(ui->button_back, SIGNAL (clicked()),this,SLOT(back()));
    initPlayGroundQTextEdit();
    createNewPlayGround();
}

Hidato5x5::~Hidato5x5()
{
    delete ui;
}


void Hidato5x5::checkSolution()
{
    for(int i = 0; i < 5; i++){
        for(int j =0; j< 5; j++){
            if(playground->getPlayGroundSolved()[i][j] == playGroundQTextEdit5x5[i*5+j]->toPlainText().toInt()){
                qInfo() << playGroundQTextEdit5x5[i*5+j]->toPlainText().toInt();
                qInfo() << "true";
                playGroundQTextEdit5x5[i*5+j]->setTextColor(Qt::green);
                playGroundQTextEdit5x5[i*5+j]->setPlainText(playGroundQTextEdit5x5[i*5+j]->toPlainText());
            }else{
                playGroundQTextEdit5x5[i*5+j]->setTextColor(Qt::red);
                playGroundQTextEdit5x5[i*5+j]->setPlainText(playGroundQTextEdit5x5[i*5+j]->toPlainText());
                qInfo() << playGroundQTextEdit5x5[i*5+j]->toPlainText().toInt();
                qInfo() << "false";
            }
            playGroundQTextEdit5x5[i*5+j]->setAlignment(Qt::AlignCenter);

        }
    }

}

void Hidato5x5::newGame()
{
     createNewPlayGround();

}

void Hidato5x5::createNewPlayGround(){
    playground->generateField();
    playground->fillPlayGround();


    for(int i = 0; i < 5; i++){
        for(int j = 0; j< 5; j++){
            playGroundQTextEdit5x5[i*5+j]->setTextColor(Qt::black);
            playGroundQTextEdit5x5[i*5+j]->setReadOnly(false);
            if(playground->getPlayGroundUnsolved()[i][j] != 0){
                playGroundQTextEdit5x5[i*5+j]->setTextColor(Qt::blue);
                playGroundQTextEdit5x5[i*5+j]->setText(QString::number(playground->getPlayGroundUnsolved()[i][j]));
                playGroundQTextEdit5x5[i*5+j]->setReadOnly(true);

            }else {
                playGroundQTextEdit5x5[i*5+j]->clear();
            }
            playGroundQTextEdit5x5[i*5+j]->setAlignment(Qt::AlignCenter);
        }
    }
}

void Hidato5x5::back(){
    mainMenu = new ChooseWindow(0);
    mainMenu->show();
    this->hide();

}

void Hidato5x5::initPlayGroundQTextEdit()
{
    playGroundQTextEdit5x5.push_back(ui->text_number_0);
    playGroundQTextEdit5x5.push_back(ui->text_number_1);
    playGroundQTextEdit5x5.push_back(ui->text_number_2);
    playGroundQTextEdit5x5.push_back(ui->text_number_3);
    playGroundQTextEdit5x5.push_back(ui->text_number_4);
    playGroundQTextEdit5x5.push_back(ui->text_number_5);
    playGroundQTextEdit5x5.push_back(ui->text_number_6);
    playGroundQTextEdit5x5.push_back(ui->text_number_7);
    playGroundQTextEdit5x5.push_back(ui->text_number_8);
    playGroundQTextEdit5x5.push_back(ui->text_number_9);
    playGroundQTextEdit5x5.push_back(ui->text_number_10);
    playGroundQTextEdit5x5.push_back(ui->text_number_11);
    playGroundQTextEdit5x5.push_back(ui->text_number_12);
    playGroundQTextEdit5x5.push_back(ui->text_number_13);
    playGroundQTextEdit5x5.push_back(ui->text_number_14);
    playGroundQTextEdit5x5.push_back(ui->text_number_15);
    playGroundQTextEdit5x5.push_back(ui->text_number_16);
    playGroundQTextEdit5x5.push_back(ui->text_number_17);
    playGroundQTextEdit5x5.push_back(ui->text_number_18);
    playGroundQTextEdit5x5.push_back(ui->text_number_19);
    playGroundQTextEdit5x5.push_back(ui->text_number_20);
    playGroundQTextEdit5x5.push_back(ui->text_number_21);
    playGroundQTextEdit5x5.push_back(ui->text_number_22);
    playGroundQTextEdit5x5.push_back(ui->text_number_23);
    playGroundQTextEdit5x5.push_back(ui->text_number_24);
}
