// imagewidget.h
#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QNetworkAccessManager>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = nullptr);

    QPixmap getCurrentImage(); // 給遊戲用

private slots:
    void loadImage();
    void onImageDownloaded(QNetworkReply* reply);

private:
    QLabel *imageLabel;
    QPushButton *loadButton;
    QLineEdit *keywordEdit;
    QVBoxLayout *layout;
    QNetworkAccessManager *manager;
    QPixmap currentImage;
};

#endif // IMAGEWIDGET_H
