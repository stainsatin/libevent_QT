#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <string.h>

namespace Ui {
class Widget;
}

#define IP      "110.42.167.18"
#define PORT    8887

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void client_connect_succecss();
    void client_disconnect();
    void client_reply_info();

    void on_registerButton_clicked();

    void on_loginButton_clicked();

private:
    void client_send_data(QJsonObject &);
    void client_recv_data(QByteArray &);
    void client_register_handler(QJsonObject &);
    void client_login_handler(QJsonObject &);

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};

#endif // WIDGET_H
