#include "chatlist.h"
#include "ui_chatlist.h"
#include "addfriend.h"
#include "privatechat.h"
#include "creategroup.h"
#include "addgroup.h"
#include "groupchat.h"

Chatlist::Chatlist(QTcpSocket *s, QString &f, QString &g, QString &u) :
    ui(new Ui::Chatlist)
{
    ui->setupUi(this);

    this->socket = s;
    this->friendlist = f;
    this->grouplist = g;
    this->username = u;

    //qDebug() << friendlist << grouplist;

    //初始化好友和群信息
    if (friendlist.isEmpty())
    {

    }
    else if (!friendlist.contains('|'))
    {
        ui->friendList->addItem(friendlist);
    }
    else
    {
        QStringList friList = friendlist.split('|');
        for (int i = 0; i < friList.size(); i++)
        {
            if (friList.at(i) != "")
            {
                ui->friendList->addItem(friList.at(i));
            }
        }
    }

    if (grouplist.isEmpty())
    {

    }
    else if (!grouplist.contains('|'))
    {
        ui->groupList->addItem(grouplist);
    }
    else
    {
        QStringList grpList = grouplist.split('|');
        for (int i = 0; i < grpList.size(); i++)
        {
            if (grpList.at(i) != "")
            {
                ui->groupList->addItem(grpList.at(i));
            }
        }
    }

    //初始化QListWidget
    QFont font("楷体", 15);

    ui->friendList->setFont(font);
    ui->friendList->setGridSize(QSize(100, 50));

    ui->groupList->setFont(font);
    ui->groupList->setGridSize(QSize(100, 50));

    //连接信号与槽
    connect(socket, &QTcpSocket::disconnected, this, &Chatlist::chat_server_disconnect);
    connect(socket, &QTcpSocket::readyRead, this, &Chatlist::chat_server_reply);

    //私聊和群聊连接信号与槽
    connect(ui->friendList, &QListWidget::itemDoubleClicked, this, &Chatlist::chat_private_slot);
    connect(ui->groupList, &QListWidget::itemDoubleClicked, this, &Chatlist::chat_group_slot);
}

Chatlist::~Chatlist()
{
    delete ui;
}

void Chatlist::chat_private_slot()
{
    QString friendName = ui->friendList->currentItem()->text();
    QString str = QString("跟%1聊天..").arg(friendName);

    //判断窗口是否已经打开
    for (int i = 0; i < pList.size(); i++)
    {
        if (pList.at(i).friendName == friendName)
        {
            pList.at(i).p_wiget->activateWindow();
            return;
        }
    }

    //启动新窗口
    PrivateChat *m_private = new PrivateChat(&pList, username, friendName, this);
    m_private->setWindowTitle(str);
    m_private->show();

    PrivateWidgetInfo p = {m_private, friendName};
    pList.push_back(p);
}

void Chatlist::chat_group_slot()
{
    QString groupName = ui->groupList->currentItem()->text();

    //判断窗口是否打开
    for (int i = 0; i < gList.size(); i++)
    {
        if (gList.at(i).groupName == groupName)
        {
            gList.at(i).g_widget->activateWindow();
            return;
        }
    }

    //如果窗口没有打开
    QJsonObject obj;
    obj.insert("cmd", "groupmember");
    obj.insert("groupname", groupName);

    chat_send_data(obj);

    GroupChat *m_group = new GroupChat(&gList, username, groupName, this);
    m_group->setWindowTitle("群聊");
    m_group->show();

    GroupWidgetInfo g = {m_group, groupName};
    gList.push_back(g);
}

void Chatlist::chat_server_reply()
{
    QByteArray ba;
    chat_read_data(ba);

    QJsonObject obj = QJsonDocument::fromJson(ba).object();

    QString cmd = obj.value("cmd").toString();

    if (cmd == "online")
    {
        chat_online_reply(obj);
    }
    else if (cmd == "addfriend_reply")
    {
        chat_add_friend_reply(obj);
    }
    else if (cmd == "be_addfriend")
    {
        chat_be_add_friend_reply(obj);
    }
    else if (cmd == "private_reply")
    {
        chat_private_reply(obj);
    }
    else if (cmd == "private")
    {
        chat_friend_private_reply(obj);
    }
    else if (cmd == "creategroup_reply")
    {
        chat_create_group_reply(obj);
    }
    else if (cmd == "joingroup_reply")
    {
        chat_join_group_reply(obj);
    }
    else if (cmd == "new_member_join")
    {
        chat_new_member_join_reply(obj);
    }
    else if (cmd == "groupmember_reply")
    {
        chat_group_member_reply(obj);
    }
    else if (cmd == "groupchat_reply")
    {
        chat_group_reply(obj);
    }
    else if (cmd == "file_reply")
    {
        chat_file_reply(obj);
    }
    else if (cmd == "file_name")
    {
        chat_file_name_reply(obj);
    }
    else if (cmd == "file_transfer")
    {
        chat_file_transfer_reply(obj);
    }
    else if (cmd == "file_end")
    {
        chat_file_end_reply();
    }
    else if (cmd == "friend_offline")
    {
        chat_friend_offline_reply(obj);
    }
}

void Chatlist::chat_friend_offline_reply(QJsonObject &obj)
{
    QString str = QString("%1下线").arg(obj.value("username").toString());

    QMessageBox::information(this, "下线提醒", str);
}

void Chatlist::chat_file_end_reply()
{
    recvFile.m_file->close();
    delete recvFile.m_file;

    QString str = QString("%1给你发送了一个文件").arg(recvFile.fromUser);
    QMessageBox::information(this, "文件传输", str);
}

void Chatlist::chat_file_transfer_reply(QJsonObject &obj)
{
    QString text = obj.value("text").toString();
    QByteArray writeData;
    writeData.append(text);
    recvFile.m_file->write(writeData);
}

void Chatlist::chat_file_name_reply(QJsonObject &obj)
{
    QString str = obj.value("filename").toString();
    int idx = str.lastIndexOf('/');
    recvFile.fileName = str.right(str.length() - idx - 1);
    recvFile.length = obj.value("filelength").toInt();
    recvFile.fromUser = obj.value("fromuser").toString();
    recvFile.m_file = new QFile(recvFile.fileName);
    recvFile.m_file->open(QIODevice::WriteOnly);
}

void Chatlist::chat_file_reply(QJsonObject &obj)
{
    QString result = obj.value("result").toString();

    if (result == "offline")
    {
        emit signal_stop_file();
    }
    else if (result == "online")
    {
        emit signal_start_file();
    }
}

void Chatlist::chat_group_reply(QJsonObject &obj)
{
    QString groupName = obj.value("groupname").toString();

    for (int i = 0; i < gList.size(); i++)
    {
        if (gList.at(i).groupName == groupName)
        {
            gList.at(i).g_widget->activateWindow();
            emit signal_to_group_chat(obj);
            return;
        }
    }

    //创建新窗口对象
    QJsonObject sendObj;
    sendObj.insert("cmd", "groupmember");
    sendObj.insert("groupname", groupName);

    chat_send_data(sendObj);

    GroupChat *m_group = new GroupChat(&gList, username, groupName, this);
    m_group->setWindowTitle("群聊");
    m_group->show();

    GroupWidgetInfo g = {m_group, groupName};
    gList.push_back(g);

    emit signal_to_group_chat(obj);
}

void Chatlist::chat_new_member_join_reply(QJsonObject &obj)
{
    QString groupName = obj.value("groupname").toString();
    QString userName = obj.value("username").toString();

    for (int i = 0; i < gList.size(); i++)
    {
        if (gList.at(i).groupName == groupName)
        {
            gList.at(i).g_widget->group_refresh_member(userName);
            break;
        }
    }
}

void Chatlist::chat_group_member_reply(QJsonObject &obj)
{
    emit signal_to_group_slot(obj);
}

void Chatlist::chat_join_group_reply(QJsonObject &obj)
{
    QString result = obj.value("result").toString();

    if (result == "not_exist")
    {
        QMessageBox::warning(this, "加群提示", "群不存在");
    }
    else if (result == "already")
    {
        QMessageBox::warning(this, "加群提示", "已经在群里");
    }
    else if (result == "success")
    {
        QString groupName = obj.value("groupname").toString();
        ui->groupList->addItem(groupName);
    }
}

void Chatlist::chat_create_group_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "exist")
    {
        QMessageBox::warning(this, "建群提示", "群已经存在");
    }
    else if (obj.value("result").toString() == "success")
    {
        QString groupName = obj.value("groupname").toString();
        ui->groupList->addItem(groupName);
    }
}

void Chatlist::chat_friend_private_reply(QJsonObject &obj)
{
    QString friendName = obj.value("fromfriend").toString();
    QString str = QString("跟%1聊天..").arg(friendName);

    //判断窗口是否已经打开
    for (int i = 0; i < pList.size(); i++)
    {
        if (pList.at(i).friendName == friendName)
        {
            pList.at(i).p_wiget->activateWindow();
            emit signal_to_private_chat(obj);
            return;
        }
    }

    //启动新窗口
    PrivateChat *m_private = new PrivateChat(&pList, username, friendName, this);
    m_private->setWindowTitle(str);
    m_private->show();

    PrivateWidgetInfo p = {m_private, friendName};
    pList.push_back(p);

    emit signal_to_private_chat(obj);

}

void Chatlist::chat_private_reply(QJsonObject &obj)
{
    if (obj.value("result").toString() == "offline")
    {
        QMessageBox::warning(this, "聊天提示", "对方不在线");
    }
}

void Chatlist::chat_be_add_friend_reply(QJsonObject &obj)
{
    QString info = QString("%1把你添加为好友").arg(obj.value("friend").toString());
    QMessageBox::information(this, "添加提示", info);

    ui->friendList->addItem(obj.value("friend").toString());
}

void Chatlist::chat_add_friend_reply(QJsonObject &obj)
{
    QString result = obj.value("result").toString();

    if (result == "not_exist")
    {
        QMessageBox::warning(this, "添加提示", "好友不存在");
    }
    else if (result == "already_friend")
    {
        QMessageBox::warning(this, "添加提示", "已经是好友关系");
    }
    else if (result == "success")
    {
        QMessageBox::information(this, "添加提示", "添加成功");

        ui->friendList->addItem(obj.value("friend").toString());
    }
}

void Chatlist::chat_online_reply(QJsonObject &obj)
{
    QString info = QString("%1好友上线").arg(obj.value("username").toString());
    QMessageBox::information(this, "上线提示", info);
}

void Chatlist::chat_read_data(QByteArray &ba)
{
    char buf[1024] = {0};
    int size, sum = 0;
    bool flag = true;

    socket->read(buf, 4);
    memcpy(&size, buf, 4);

    qDebug() << "get data len : " << size;

    while (flag)
    {
        memset(buf, 0, 1024);
        sum += socket->read(buf, size - sum);
        if (sum >= size)
        {
            flag = false;
        }

        ba.append(buf);
    }

    qDebug() << "data : " << ba;
}

void Chatlist::chat_server_disconnect()
{
    QMessageBox::warning(this, "连接提示", "服务器断开");
}

void Chatlist::chat_send_data(QJsonObject &obj)
{
    QByteArray sendData;
    QByteArray ba = QJsonDocument(obj).toJson();

    int size = ba.size();

    sendData.insert(0, (char *)&size, 4);
    sendData.append(ba);

    socket->write(sendData);

    socket->flush();
}

void Chatlist::on_addButton_clicked()
{
    //创建新的界面
    AddFriend *add = new AddFriend(username, this);
    add->setWindowTitle("添加好友");
    add->show();
}

void Chatlist::on_createButton_clicked()
{
    CreateGroup *createGroup = new CreateGroup(username, this);
    createGroup->setWindowTitle("创建群聊");
    createGroup->show();
}

void Chatlist::on_joinButton_clicked()
{
    AddGroup *addGroup = new AddGroup(username, this);
    addGroup->setWindowTitle("加入群聊");
    addGroup->show();
}

void Chatlist::closeEvent(QCloseEvent *e)
{
    QJsonObject obj;
    obj.insert("cmd", "offline");
    obj.insert("username", username);

    chat_send_data(obj);

    socket->disconnect(SIGNAL(disconnected()));

    socket->close();

    socket->deleteLater();

    e->accept();
}
