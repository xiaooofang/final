// gamewidget.h
#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class ImageWidget;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(ImageWidget* imgWidget, QWidget *parent = nullptr);

private slots:
    void startGame();
    void popUpMole();
    void hitMole();

private:
    QLabel *scoreLabel;
    QPushButton *startButton;
    int score;
    QTimer *timer;
    QPushButton *buttons[9];
    int currentMoleIndex;
    ImageWidget* imgWidget;
    int speed; // 控制遊戲速度
};

#endif // GAMEWIDGET_H
