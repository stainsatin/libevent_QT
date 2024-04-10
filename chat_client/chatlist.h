#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include "privatechat.h"
#include "groupchat.h"
#include <QFile>
#include <QCloseEvent>

namespace Ui {
class Chatlist;
}

struct FileInfo
{
    QString fileName;
    QString fromUser;
    int length;
    QFile *m_file;
};

class Chatlist : public QWidget
{
    Q_OBJECT

public:
    explicit Chatlist(QTcpSocket *, QString &, QString &, QString &);

    void chat_send_data(QJsonObject &);

    void closeEvent(QCloseEvent *);

    ~Chatlist();

private slots:
    void chat_server_reply();
    void chat_server_disconnect();
    void chat_private_slot();
    void chat_group_slot();

    void on_addButton_clicked();

    void on_createButton_clicked();

    void on_joinButton_clicked();

private:
    void chat_read_data(QByteArray &);
    void chat_online_reply(QJsonObject &);
    void chat_add_friend_reply(QJsonObject &);
    void chat_be_add_friend_reply(QJsonObject &);
    void chat_private_reply(QJsonObject &);
    void chat_friend_private_reply(QJsonObject &);
    void chat_create_group_reply(QJsonObject &);
    void chat_join_group_reply(QJsonObject &);
    void chat_group_member_reply(QJsonObject &);
    void chat_new_member_join_reply(QJsonObject &);
    void chat_group_reply(QJsonObject &);
    void chat_file_reply(QJsonObject &);
    void chat_file_name_reply(QJsonObject &);
    void chat_file_transfer_reply(QJsonObject &);
    void chat_file_end_reply();
    void chat_friend_offline_reply(QJsonObject &);

signals:
    void signal_to_private_chat(QJsonObject &);
    void signal_to_group_slot(QJsonObject &);
    void signal_to_group_chat(QJsonObject &);
    void signal_start_file();
    void signal_stop_file();

private:
    Ui::Chatlist *ui;
    QTcpSocket *socket;
    QString friendlist;
    QString grouplist;
    QString username;
    QList<PrivateWidgetInfo> pList;
    QList<GroupWidgetInfo> gList;
    FileInfo recvFile;
};

#endif // CHATLIST_H
