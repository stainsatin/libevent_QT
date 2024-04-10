#include "groupchat.h"
#include "ui_groupchat.h"
#include "chatlist.h"
#include <QStringList>

GroupChat::GroupChat(QList<GroupWidgetInfo> *grp, QString u, QString g, Chatlist *c) :
    ui(new Ui::GroupChat)
{
    ui->setupUi(this);
    this->gList = grp;
    this->userName = u;
    this->groupName = g;
    this->m_chat = c;

    ui->label->setText(groupName);

    //服务器回复群成员信息，chatlist发出信号
    connect(m_chat, &Chatlist::signal_to_group_slot, this, &GroupChat::group_show_member_slot);
    connect(m_chat, &Chatlist::signal_to_group_chat, this, &GroupChat::group_show_text_slot);
}

GroupChat::~GroupChat()
{
    delete ui;
}

void GroupChat::group_show_member_slot(QJsonObject &obj)
{
    QString member = obj.value("member").toString();

    if (!member.contains('|'))
    {
        ui->listWidget->addItem(member);
    }
    else
    {
        QStringList memberList = member.split('|');
        for (int i = 0; i < memberList.size(); i++)
        {
            ui->listWidget->addItem(memberList.at(i));
        }
    }
}

void GroupChat::group_refresh_member(QString userName)
{
    ui->listWidget->addItem(userName);
}

void GroupChat::on_pushButton_clicked()
{
    QString msg = ui->lineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "groupchat");
    obj.insert("groupname", groupName);
    obj.insert("username", userName);
    obj.insert("text", msg);

    m_chat->chat_send_data(obj);

    msg.insert(0, "我：");
    m_text.append(msg);

    ui->textEdit->setText(m_text);

    ui->lineEdit->clear();
}

void GroupChat::on_lineEdit_returnPressed()
{
    QString msg = ui->lineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "groupchat");
    obj.insert("groupname", groupName);
    obj.insert("username", userName);
    obj.insert("text", msg);

    m_chat->chat_send_data(obj);

    msg.insert(0, "我：");
    m_text.append(msg);
    m_text.append("\n");

    ui->textEdit->setText(m_text);

    ui->lineEdit->clear();
}

void GroupChat::closeEvent(QCloseEvent *e)
{
    for (int i = 0; i < gList->size(); i++)
    {
        if (gList->at(i).g_widget == this)
        {
            gList->removeAt(i);
            break;
        }
    }

    e->accept();
}

void GroupChat::group_show_text_slot(QJsonObject &obj)
{
    QString msg = obj.value("text").toString();
    QString fromName = obj.value("from").toString();

    fromName.append("：");
    fromName.append(msg);

    m_text.append(fromName);
    m_text.append("\n");

    ui->textEdit->setText(m_text);
}
