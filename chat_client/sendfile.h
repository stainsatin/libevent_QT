#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QString, QString);

    void thread_send_data(QJsonObject &obj);

signals:
    void thread_connect_timeout();

    void thread_send_finish();

public slots:
    void working();    //子线程工作函数

private:
    QString fileName;
    QString friendName;
    QTcpSocket *sendSocket;
};

#endif // SENDFILE_H
