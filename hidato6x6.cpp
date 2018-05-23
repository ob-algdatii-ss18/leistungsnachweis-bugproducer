#include "hidato6x6.h"
#include "ui_hidato6x6.h"
#include <QDebug>


Hidato6x6::Hidato6x6(QWidget *parent) :
    QMainWindow(parent),
    playground(new PlayGround(6,-1)),
    ui(new Ui::Hidato6x6)
{
    ui->setupUi(this);
    connect(ui->button_check, SIGNAL (clicked()),this,SLOT(checkSolution()));
    connect(ui->button_new, SIGNAL (clicked()),this,SLOT(newGame()));
    initPlayGroundQTextEdit();
    createNewPlayGround();
}

Hidato6x6::~Hidato6x6()
{
    delete ui;
}
void Hidato6x6::initPlayGroundQTextEdit()
{
    playGroundQTextEdit6x6.push_back(ui->text_number_0);
    playGroundQTextEdit6x6.push_back(ui->text_number_1);
    playGroundQTextEdit6x6.push_back(ui->text_number_2);
    playGroundQTextEdit6x6.push_back(ui->text_number_3);
    playGroundQTextEdit6x6.push_back(ui->text_number_4);
    playGroundQTextEdit6x6.push_back(ui->text_number_5);
    playGroundQTextEdit6x6.push_back(ui->text_number_6);
    playGroundQTextEdit6x6.push_back(ui->text_number_7);
    playGroundQTextEdit6x6.push_back(ui->text_number_8);
    playGroundQTextEdit6x6.push_back(ui->text_number_9);
    playGroundQTextEdit6x6.push_back(ui->text_number_10);
    playGroundQTextEdit6x6.push_back(ui->text_number_11);
    playGroundQTextEdit6x6.push_back(ui->text_number_12);
    playGroundQTextEdit6x6.push_back(ui->text_number_13);
    playGroundQTextEdit6x6.push_back(ui->text_number_14);
    playGroundQTextEdit6x6.push_back(ui->text_number_15);
    playGroundQTextEdit6x6.push_back(ui->text_number_16);
    playGroundQTextEdit6x6.push_back(ui->text_number_17);
    playGroundQTextEdit6x6.push_back(ui->text_number_18);
    playGroundQTextEdit6x6.push_back(ui->text_number_19);
    playGroundQTextEdit6x6.push_back(ui->text_number_20);
    playGroundQTextEdit6x6.push_back(ui->text_number_21);
    playGroundQTextEdit6x6.push_back(ui->text_number_22);
    playGroundQTextEdit6x6.push_back(ui->text_number_23);
    playGroundQTextEdit6x6.push_back(ui->text_number_24);
    playGroundQTextEdit6x6.push_back(ui->text_number_25);
    playGroundQTextEdit6x6.push_back(ui->text_number_26);
    playGroundQTextEdit6x6.push_back(ui->text_number_27);
    playGroundQTextEdit6x6.push_back(ui->text_number_28);
    playGroundQTextEdit6x6.push_back(ui->text_number_29);
    playGroundQTextEdit6x6.push_back(ui->text_number_30);
    playGroundQTextEdit6x6.push_back(ui->text_number_31);
    playGroundQTextEdit6x6.push_back(ui->text_number_32);
    playGroundQTextEdit6x6.push_back(ui->text_number_33);
    playGroundQTextEdit6x6.push_back(ui->text_number_34);
    playGroundQTextEdit6x6.push_back(ui->text_number_35);

}

void Hidato6x6::checkSolution()
{
    for(int i = 0; i < 6; i++){
        for(int j =0; j< 6; j++){
            if(playground->getPlayGroundSolved()[i][j] == playGroundQTextEdit6x6[i*6+j]->toPlainText().toInt()){
                qInfo() << playGroundQTextEdit6x6[i*6+j]->toPlainText().toInt();
                qInfo() << "true";
                playGroundQTextEdit6x6[i*6+j]->setTextColor(Qt::green);
                playGroundQTextEdit6x6[i*6+j]->setPlainText(playGroundQTextEdit6x6[i*6+j]->toPlainText());
            }else{
                playGroundQTextEdit6x6[i*6+j]->setTextColor(Qt::red);
                playGroundQTextEdit6x6[i*6+j]->setPlainText(playGroundQTextEdit6x6[i*6+j]->toPlainText());
                qInfo() << playGroundQTextEdit6x6[i*6+j]->toPlainText().toInt();
                qInfo() << "false";
            }
            playGroundQTextEdit6x6[i*6+j]->setAlignment(Qt::AlignCenter);

        }
    }

}

void Hidato6x6::newGame()
{
     createNewPlayGround();

}

void Hidato6x6::createNewPlayGround()
{
    playground->generateField();
    playground->fillPlayGround();


    for(int i = 0; i < 6; i++){
        for(int j =0; j< 6; j++){

            playGroundQTextEdit6x6[i*6+j]->setTextColor(Qt::black);
            playGroundQTextEdit6x6[i*6+j]->setReadOnly(false);

            if(playground->getPlayGroundUnsolved()[i][j] != 0){
                playGroundQTextEdit6x6[i*6+j]->setTextColor(Qt::blue);
                playGroundQTextEdit6x6[i*6+j]->setText(QString::number(playground->getPlayGroundUnsolved()[i][j]));
                playGroundQTextEdit6x6[i*6+j]->setReadOnly(true);

            }else {
                playGroundQTextEdit6x6[i*6+j]->clear();
            }
            playGroundQTextEdit6x6[i*6+j]->setAlignment(Qt::AlignCenter);
        }
    }
}

