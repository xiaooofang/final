// gamewidget.cpp
#include "gamewidget.h"
#include "imagewidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QMessageBox>

GameWidget::GameWidget(ImageWidget* imgWidget, QWidget *parent)
    : QWidget(parent), imgWidget(imgWidget), score(0), currentMoleIndex(-1), speed(1000)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    scoreLabel = new QLabel("Score: 0");
    mainLayout->addWidget(scoreLabel);

    startButton = new QPushButton("開始遊戲");
    mainLayout->addWidget(startButton);
    connect(startButton, &QPushButton::clicked, this, &GameWidget::startGame);

    QGridLayout* grid = new QGridLayout;
    for(int i=0;i<9;i++){
        buttons[i] = new QPushButton;
        buttons[i]->setFixedSize(80,80);
        grid->addWidget(buttons[i], i/3, i%3);
        connect(buttons[i], &QPushButton::clicked, this, &GameWidget::hitMole);
    }
    mainLayout->addLayout(grid);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameWidget::popUpMole);
}

void GameWidget::startGame()
{
    score = 0;
    speed = 1000;
    scoreLabel->setText("Score: 0");
    timer->start(speed);
    startButton->setEnabled(false);
}

void GameWidget::popUpMole()
{
    // 清除前一隻地鼠
    if(currentMoleIndex != -1)
        buttons[currentMoleIndex]->setIcon(QIcon());

    // 隨機出現新地鼠
    currentMoleIndex = QRandomGenerator::global()->bounded(9);
    QPixmap mole = imgWidget->getCurrentImage().scaled(60,60);
    buttons[currentMoleIndex]->setIcon(QIcon(mole));
    buttons[currentMoleIndex]->setIconSize(QSize(60,60));

    // 加快遊戲速度
    if(speed > 300){
        speed -= 20; // 每次出現越快
        timer->start(speed);
    }
}

void GameWidget::hitMole()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());

    if(btn == buttons[currentMoleIndex]){
        score++;
        btn->setIcon(QIcon());
        currentMoleIndex = -1;
    } else {
        score--;
        if(score <= 0){
            score = 0;
            timer->stop();
            startButton->setEnabled(true);
            QMessageBox::information(this, "遊戲結束", "分數歸零，遊戲結束！");
        }
    }
    scoreLabel->setText(QString("Score: %1").arg(score));
}
