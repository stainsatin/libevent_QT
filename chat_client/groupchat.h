#ifndef GROUPCHAT_H
#define GROUPCHAT_H

#include <QWidget>
#include <QJsonObject>
#include <QCloseEvent>

namespace Ui {
class GroupChat;
}

class GroupChat;
class Chatlist;

struct GroupWidgetInfo
{
    GroupChat *g_widget;
    QString groupName;
};

class GroupChat : public QWidget
{
    Q_OBJECT

public:
    explicit GroupChat(QList<GroupWidgetInfo> *, QString, QString, Chatlist *);
    ~GroupChat();

    void group_refresh_member(QString);

    void closeEvent(QCloseEvent *);

private slots:
    void group_show_member_slot(QJsonObject &);

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void group_show_text_slot(QJsonObject &);

private:
    Ui::GroupChat *ui;
    QList<GroupWidgetInfo> *gList;
    QString userName;
    QString groupName;
    Chatlist *m_chat;
    QString m_text;
};

#endif // GROUPCHAT_H
