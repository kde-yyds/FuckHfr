#include "myscene.h"
#include <stdlib.h>

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    int width = 160;
    int height = 160;
    for(int i = 0; i < 16; i++){
        this->item[i] = new myItem;
        this->item[i]->setPos(i/4 * width,i%4 *height);
        this->addItem(this->item[i]);

    }
    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
}
void myScene::showMouse(){
    for(int i = 0;i < 16;i++){
        this->item[i]->setPic(":/bg/bg.png");
    }
    int count = rand()%3 + 1;
    for(int i = 0; i < count; i++){
        int index = rand()%16;
        this->item[index]->setPic(":/bg/bg1.png");
        this->item[index]->setMouse(true);
    }
}

void myScene::startGame(){
    for(int i = 0;i < 16;i++){
        this->item[i]->setStart(true);
    }
    this->ptimer->start(1000);
}

void myScene::pauseGame(){
    this->ptimer->stop();
    for(int i = 0;i < 16;i++){
        this->item[i]->setStart(false);
    }
}

void myScene::stopGame(){
    this->ptimer->stop();
    for(int i = 0;i < 16;i++){
        this->item[i]->setPic(":/bg/bg.png");
        this->item[i]->setMouse(false);
    }
    for(int i = 0;i < 16;i++){
        this->item[i]->setStart(false);
    }
}
