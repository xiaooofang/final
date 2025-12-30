#include "chatwidget.h"
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

ChatWidget::ChatWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Mini Chatroom");
    title->setAlignment(Qt::AlignCenter);

    chatView = new QTextBrowser;
    input = new QLineEdit;
    QPushButton *sendBtn = new QPushButton("Send");

    layout->addWidget(title);
    layout->addWidget(chatView);
    layout->addWidget(input);
    layout->addWidget(sendBtn);

    connect(sendBtn, &QPushButton::clicked,
            this, &ChatWidget::sendMessage);
}

void ChatWidget::sendMessage()
{
    QString text = input->text();
    if (text.isEmpty()) return;

    chatView->append("You: " + text);
    chatView->append("Bot: Nice message!");
    input->clear();
}
