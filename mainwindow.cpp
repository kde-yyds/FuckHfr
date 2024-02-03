#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handler.h"
#include <QPropertyAnimation>
#include <iostream>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);

    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this,SLOT(clearScore()));

    this->score = 0;
    handler *hand = handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateScore(){
    this->score += 10;
//    this->ui->lcdNumber->display(this->score);
    this->ui->label->setNum(this->score);
}
void MainWindow::clearScore(){
//    this->ui->lcdNumber->display("0");
    this->ui->label->setNum(0);
}

void MainWindow::on_pushButton_clicked()
{
    ifHide = !ifHide;
    if (ifHide)
    {
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->scrollArea_2, "geometry"};
        animation->setDuration(2000);
        animation->setStartValue(this->ui->scrollArea_2->geometry());
        animation->setEndValue(QRect(0, 40, 835, 0));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();

        QPropertyAnimation *animation2 = new QPropertyAnimation {this->ui->scrollArea, "geometry"};
        animation2->setDuration(2000);
        animation2->setStartValue(this->ui->scrollArea->geometry());
        animation2->setEndValue(QRect(100, 60, 611, 651));
        animation2->setEasingCurve(QEasingCurve::OutExpo);
        animation2->start();

        this->ui->pushButton->setText("开 始 游 戏");
    }
    else
    {
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->scrollArea_2, "geometry"};
        animation->setDuration(2000);
        animation->setStartValue(this->ui->scrollArea_2->geometry());
        animation->setEndValue(QRect(0, 40, 835, 651));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();

        QPropertyAnimation *animation2 = new QPropertyAnimation {this->ui->scrollArea, "geometry"};
        animation2->setDuration(2000);
        animation2->setStartValue(this->ui->scrollArea->geometry());
        animation2->setEndValue(QRect(420, 720, 0, 0));
        animation2->setEasingCurve(QEasingCurve::OutExpo);
        animation2->start();

        this->ui->pushButton->setText("隐 藏 游 戏");
    }


}


void MainWindow::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/kde-yyds/FuckHfr"));
}


void MainWindow::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/kde-yyds/FuckHfr/issues/new"));
}


void MainWindow::on_pushButton_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://space.bilibili.com/2008726064"));
}


void MainWindow::on_pushButton_6_clicked()
{
    QDesktopServices::openUrl(QUrl("https://search.bilibili.com/all?keyword=山竹醇"));
}

