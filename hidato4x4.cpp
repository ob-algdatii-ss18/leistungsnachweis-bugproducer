#include "hidato4x4.h"
#include "ui_hidato4x4.h"
#include <QDebug>
#include "choosewindow.h"



Hidato4x4::Hidato4x4(QWidget *parent) :
    QMainWindow(parent),
    playground(new PlayGround(4,-1)),
    ui(new Ui::Hidato4x4)
{
    ui->setupUi(this);
    connect(ui->button_check, SIGNAL (clicked()),this,SLOT(checkSolution()));
    connect(ui->button_new, SIGNAL (clicked()),this,SLOT(newGame()));
    connect(ui->button_back, SIGNAL (clicked()),this,SLOT(back()));
    initPlayGroundQTextEdit();
    createNewPlayGround();
}

Hidato4x4::~Hidato4x4()
{
    delete ui;
    delete playground;
    //delete mainMenu;

}

void Hidato4x4::checkSolution()
{   std::vector<std::vector<int>> playGroundMySolution;
    playGroundMySolution = std::vector<std::vector<int>>(4, std::vector<int>(4));
    ui->button_check->setDisabled(true);

    for(int i = 0; i < 4; i++){
        for(int j =0; j< 4; j++){
            playGroundMySolution[i][j]=playGroundQTextEdit4x4[i*4+j]->toPlainText().toInt();
        }
    }

    playground->setPlayGroundPlayerSolution(playGroundMySolution);
    for(int i = 0; i < 4; i++){
        for(int j =0; j< 4; j++){
            if(playground->checkSolution()){
                if(playground->getPlayGroundUnsolved()[i][j]==0){
                    playGroundQTextEdit4x4[i*4+j]->setTextColor(Qt::green);
                    playGroundQTextEdit4x4[i*4+j]->setPlainText(playGroundQTextEdit4x4[i*4+j]->toPlainText());
                }
            }
            else{
                if(playground->getPlayGroundUnsolved()[i][j]==0){
                    playGroundQTextEdit4x4[i*4+j]->setTextColor(Qt::red);
                    playGroundQTextEdit4x4[i*4+j]->setPlainText(playGroundQTextEdit4x4[i*4+j]->toPlainText());
                }
            }
            playGroundQTextEdit4x4[i*4+j]->setAlignment(Qt::AlignCenter);
            playGroundQTextEdit4x4[i*4+j]->setReadOnly(true);


        }
    }
}

void Hidato4x4::newGame()
{
    createNewPlayGround();
    ui->button_check->setDisabled(false);

}

void Hidato4x4::createNewPlayGround(){
    playground->generatePlayground();
    playground->fillPlayGround();


    for(int i = 0; i < 4; i++){
        for(int j =0; j< 4; j++){

            playGroundQTextEdit4x4[i*4+j]->setTextColor(Qt::black);
            playGroundQTextEdit4x4[i*4+j]->setReadOnly(false);

            if(playground->getPlayGroundUnsolved()[i][j] > 0){
                playGroundQTextEdit4x4[i*4+j]->setTextColor(Qt::blue);
                playGroundQTextEdit4x4[i*4+j]->setText(QString::number(playground->getPlayGroundUnsolved()[i][j]));
                playGroundQTextEdit4x4[i*4+j]->setReadOnly(true);
            }
            else if(playground->getPlayGroundUnsolved()[i][j] == -1){
                playGroundQTextEdit4x4[i*4+j]->setTextColor(Qt::blue);
                playGroundQTextEdit4x4[i*4+j]->setText("X");
                playGroundQTextEdit4x4[i*4+j]->setReadOnly(true);

            }
            else {
                playGroundQTextEdit4x4[i*4+j]->clear();
            }
            playGroundQTextEdit4x4[i*4+j]->setAlignment(Qt::AlignCenter);
        }
    }
}

void Hidato4x4::initPlayGroundQTextEdit()
{
    playGroundQTextEdit4x4.push_back(ui->text_number_0);
    playGroundQTextEdit4x4.push_back(ui->text_number_1);
    playGroundQTextEdit4x4.push_back(ui->text_number_2);
    playGroundQTextEdit4x4.push_back(ui->text_number_3);
    playGroundQTextEdit4x4.push_back(ui->text_number_4);
    playGroundQTextEdit4x4.push_back(ui->text_number_5);
    playGroundQTextEdit4x4.push_back(ui->text_number_6);
    playGroundQTextEdit4x4.push_back(ui->text_number_7);
    playGroundQTextEdit4x4.push_back(ui->text_number_8);
    playGroundQTextEdit4x4.push_back(ui->text_number_9);
    playGroundQTextEdit4x4.push_back(ui->text_number_10);
    playGroundQTextEdit4x4.push_back(ui->text_number_11);
    playGroundQTextEdit4x4.push_back(ui->text_number_12);
    playGroundQTextEdit4x4.push_back(ui->text_number_13);
    playGroundQTextEdit4x4.push_back(ui->text_number_14);
    playGroundQTextEdit4x4.push_back(ui->text_number_15);
}

void Hidato4x4::back(){
    //ainMenu = parent();
    //mainMenu->show();
    this->parentWidget()->show();
    this->hide();
    this->~Hidato4x4();


}


