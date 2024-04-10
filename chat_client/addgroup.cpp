#include "addgroup.h"
#include "ui_addgroup.h"

AddGroup::AddGroup(QString u, Chatlist *c) :
    ui(new Ui::AddGroup)
{
    ui->setupUi(this);

    this->userName = u;
    this->m_chat = c;
}

AddGroup::~AddGroup()
{
    delete ui;
}

void AddGroup::on_cancelButton_clicked()
{
    this->close();
}

void AddGroup::on_joinButton_clicked()
{
    QString groupName = ui->lineEdit->text();
    QJsonObject obj;
    obj.insert("cmd", "joingroup");
    obj.insert("username", userName);
    obj.insert("groupname", groupName);

    m_chat->chat_send_data(obj);

    this->close();
}
