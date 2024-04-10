#include "creategroup.h"
#include "ui_creategroup.h"

CreateGroup::CreateGroup(QString u, Chatlist *c) :
    ui(new Ui::CreateGroup)
{
    ui->setupUi(this);

    this->userName = u;
    this->m_chat = c;
}

CreateGroup::~CreateGroup()
{
    delete ui;
}

void CreateGroup::on_cancelButton_clicked()
{
    this->close();
}

void CreateGroup::on_createButton_clicked()
{
    QString groupName = ui->lineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "creategroup");
    obj.insert("groupname", groupName);
    obj.insert("owner", userName);

    m_chat->chat_send_data(obj);

    this->close();
}
