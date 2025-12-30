// imagewidget.cpp
#include "imagewidget.h"
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>
#include <QUrlQuery>

ImageWidget::ImageWidget(QWidget *parent)
    : QWidget(parent)
{
    manager = new QNetworkAccessManager(this);

    imageLabel = new QLabel("圖片區");
    imageLabel->setAlignment(Qt::AlignCenter);
    keywordEdit = new QLineEdit;
    keywordEdit->setPlaceholderText("輸入關鍵字");
    loadButton = new QPushButton("載入圖片");

    layout = new QVBoxLayout(this);
    layout->addWidget(keywordEdit);
    layout->addWidget(loadButton);
    layout->addWidget(imageLabel);

    connect(loadButton, &QPushButton::clicked, this, &ImageWidget::loadImage);
    connect(manager, &QNetworkAccessManager::finished, this, &ImageWidget::onImageDownloaded);

    srand(QTime::currentTime().msec()); // 初始化隨機種子
    loadImage();
}
void ImageWidget::loadImage()
{
    QString keyword = keywordEdit->text();
    if(keyword.isEmpty()) keyword = "nature";

    // 使用舊的隨機方法
    int randNum = rand() % 1000;
    QUrl url(QString("https://picsum.photos/200/200?random=%1").arg(randNum));
    QNetworkRequest request(url);
    manager->get(request);
}
void ImageWidget::onImageDownloaded(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();
    QPixmap pix;
    pix.loadFromData(data);
    currentImage = pix;
    imageLabel->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    reply->deleteLater();
}

QPixmap ImageWidget::getCurrentImage()
{
    return currentImage;
}
