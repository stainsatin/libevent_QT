#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QString u, Chatlist *c) :
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);

    this->userName = u;
    this->m_parent = c;
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::on_cancelButton_clicked()
{
    this->close();
}

void AddFriend::on_addButton_clicked()
{
    QString friendName = ui->userEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "addfriend");
    obj.insert("username", userName);
    obj.insert("friend", friendName);

    m_parent->chat_send_data(obj);

    this->close();
}
