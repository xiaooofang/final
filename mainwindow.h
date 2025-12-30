// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ImageWidget;
class GameWidget;
class ChatWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    ImageWidget* imageWidget;
    GameWidget* gameWidget;
    ChatWidget* chatWidget;
};

#endif // MAINWINDOW_H
