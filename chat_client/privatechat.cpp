#include "privatechat.h"
#include "ui_privatechat.h"
#include "chatlist.h"
#include <QFileDialog>
#include <QCoreApplication>
#include <QThread>
#include "sendfile.h"
#include <QDebug>

PrivateChat::PrivateChat(QList<PrivateWidgetInfo> *l, QString u, QString f, Chatlist *c) :
    ui(new Ui::PrivateChat)
{
    ui->setupUi(this);

    this->pList = l;
    this->userName = u;
    this->friendName = f;
    this->m_chat = c;

    //收到chatlist信号，触发槽函数，读取聊天数据
    connect(m_chat, &Chatlist::signal_to_private_chat, this, &PrivateChat::recv_chatlist_text);
    //如果对方不在线，停止发送文件
    connect(m_chat, &Chatlist::signal_stop_file, this, &PrivateChat::stop_file_transfer);
    //如果对方在线，开始发送文件
    connect(m_chat, &Chatlist::signal_start_file, this, &PrivateChat::start_file_transfer);
}

PrivateChat::~PrivateChat()
{
    delete ui;
}

void PrivateChat::on_cancelButton_clicked()
{
    for (int i = 0; i < pList->size(); i++)
    {
        if (pList->at(i).p_wiget == this)
        {
            pList->removeAt(i);
            break;
        }
    }

    this->close();
}

void PrivateChat::closeEvent(QCloseEvent *e)
{
    for (int i = 0; i < pList->size(); i++)
    {
        if (pList->at(i).p_wiget == this)
        {
            pList->removeAt(i);
            break;
        }
    }

    //this->close();
    e->accept();
}

void PrivateChat::on_sendButton_clicked()
{
    QString text = ui->lineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "private");
    obj.insert("username", userName);
    obj.insert("tofriend", friendName);
    obj.insert("text", text);

    m_chat->chat_send_data(obj);

    text.insert(0, "我：");
    m_text.append(text);
    m_text.append("\n");

    ui->textEdit->setText(m_text);
}

void PrivateChat::on_lineEdit_returnPressed()
{
    QString text = ui->lineEdit->text();

    QJsonObject obj;
    obj.insert("cmd", "private");
    obj.insert("username", userName);
    obj.insert("tofriend", friendName);
    obj.insert("text", text);

    m_chat->chat_send_data(obj);

    text.insert(0, "我：");
    m_text.append(text);
    m_text.append("\n");

    ui->textEdit->setText(m_text);
}

void PrivateChat::recv_chatlist_text(QJsonObject &obj)
{
    QString fromName = obj.value("fromfriend").toString();
    QString text = obj.value("text").toString();

    fromName.append("：");
    text.insert(0, fromName);

    m_text.append(text);
    m_text.append("\n");

    ui->textEdit->setText(m_text);
}

void PrivateChat::on_fileButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "文件传输",
                 QCoreApplication::applicationFilePath());
    if (fileName.isEmpty())
    {
        QMessageBox::warning(this, "文件传输", "请选择一个文件");
        return;
    }

    QFile *m_file = new QFile(fileName);
    m_file->open(QIODevice::ReadOnly);

    QJsonObject obj;
    obj.insert("cmd", "file");
    obj.insert("step", "1");
    obj.insert("filename", fileName);
    obj.insert("filelength", m_file->size());
    obj.insert("friendname", friendName);
    obj.insert("username", userName);

    m_file->close();

    m_chat->chat_send_data(obj);
}

void PrivateChat::stop_file_transfer()
{
    QMessageBox::warning(this, "文件传输", "对方不在线");
}

void PrivateChat::start_file_transfer()
{
    //启动线程，开始传输文件
    //创建线程对象
    QThread *subThread = new QThread;

    //创建发送文件对象
    SendFile *mySendFile = new SendFile(fileName, friendName);

    mySendFile->moveToThread(subThread);

    //启动线程
    subThread->start();

    //通过信号启动线程工作函数
    connect(this, &PrivateChat::signal_start_send_file, mySendFile, &SendFile::working);
    emit signal_start_send_file();

    //文件传输完成
    connect(mySendFile, &SendFile::thread_send_finish, this, [=]()
    {
        subThread->quit();
        subThread->wait();
        subThread->deleteLater();
        mySendFile->deleteLater();

        QMessageBox::information(this, "文件传输", "文件发送完成");
    });

    //连接服务器超时
    connect(mySendFile, &SendFile::thread_connect_timeout, this, &PrivateChat::thread_connect_failure);
}

void PrivateChat::thread_connect_failure()
{
    QMessageBox::warning(this, "文件传输", "子线程连接服务器超时");
}
