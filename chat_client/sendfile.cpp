#include "sendfile.h"
#include <QHostAddress>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <unistd.h>
#include <QDebug>

SendFile::SendFile(QString file, QString fri)
{
    fileName = file;
    friendName = fri;

    //sendSocket = new QTcpSocket;
}

void SendFile::working()
{
    qDebug() << "---- start working ....";

    //创建socket对象
    sendSocket = new QTcpSocket;

    sendSocket->connectToHost(QHostAddress("110.42.167.18"), 8887);

    if (!sendSocket->waitForConnected(5000))
    {
        //连接服务器失败
        emit thread_connect_timeout();

        return;
    }

    //打开文件
    QFile *m_file = new QFile(fileName);
    m_file->open(QIODevice::ReadOnly);


    QByteArray readData;

    while (true)
    {
        readData.clear();

        readData = m_file->read(512);

        if (readData.isEmpty())
        {
            //文件读取完毕
            QJsonObject sendObj;
            sendObj.insert("cmd", "file");
            sendObj.insert("step", "3");
            sendObj.insert("friendname", friendName);

            thread_send_data(sendObj);

            break;
        }

        QJsonObject sendObj;
        sendObj.insert("cmd", "file");
        sendObj.insert("step", "2");
        sendObj.insert("friendname", friendName);
        sendObj.insert("text", QString(readData));

        thread_send_data(sendObj);

        usleep(100000);
    }

    m_file->close();
    delete m_file;

    sleep(1);
    sendSocket->close();
    delete sendSocket;

    //通知主线程
    qDebug() << "----- 给主线程发送信号";
    emit thread_send_finish();
}

void SendFile::thread_send_data(QJsonObject &obj)
{
    QByteArray sendData;
    QByteArray ba = QJsonDocument(obj).toJson();

    int size = ba.size();

    sendData.insert(0, (char *)&size, 4);
    sendData.append(ba);

    sendSocket->write(sendData);

    sendSocket->flush();
}
