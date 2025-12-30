#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

class QTextBrowser;
class QLineEdit;
class QPushButton;

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent = nullptr);

private slots:
    void sendMessage();

private:
    QTextBrowser *chatView;
    QLineEdit *input;
};

#endif // CHATWIDGET_H
