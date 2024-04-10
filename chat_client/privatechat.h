#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>
#include <QList>
#include <QCloseEvent>
#include <QJsonObject>

namespace Ui {
class PrivateChat;
}

class Chatlist;
class PrivateChat;

struct PrivateWidgetInfo
{
    PrivateChat *p_wiget;
    QString friendName;
};

class PrivateChat : public QWidget
{
    Q_OBJECT

public:
    explicit PrivateChat(QList<PrivateWidgetInfo> *, QString, QString, Chatlist *c);
    void closeEvent(QCloseEvent *);
    ~PrivateChat();

private slots:
    void on_cancelButton_clicked();

    void on_sendButton_clicked();

    void on_lineEdit_returnPressed();

    void recv_chatlist_text(QJsonObject &);

    void on_fileButton_clicked();

    void start_file_transfer();

    void stop_file_transfer();

    void thread_connect_failure();

signals:
    void signal_start_send_file();

private:
    Ui::PrivateChat *ui;
    QList<PrivateWidgetInfo> *pList;
    QString userName;
    QString friendName;
    Chatlist *m_chat;
    QString m_text;
    QString fileName;
};

#endif // PRIVATECHAT_H
