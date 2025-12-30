// mainwindow.cpp
#include "mainwindow.h"
#include "imagewidget.h"
#include "gamewidget.h"
#include "chatwidget.h"
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("NetScope - 打地鼠互動遊戲");
    resize(1200, 600);

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QHBoxLayout* layout = new QHBoxLayout(central);

    ImageWidget* imgWidget = new ImageWidget(this);
    GameWidget* gameWidget = new GameWidget(imgWidget, this);
    ChatWidget* chatWidget = new ChatWidget(this);

    layout->addWidget(imgWidget);
    layout->addWidget(gameWidget);
    layout->addWidget(chatWidget);

    layout->setStretch(0, 1);
    layout->setStretch(1, 2);
    layout->setStretch(2, 1);
}
