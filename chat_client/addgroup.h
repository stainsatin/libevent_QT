#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QWidget>
#include "chatlist.h"
#include <QJsonObject>

namespace Ui {
class AddGroup;
}

class AddGroup : public QWidget
{
    Q_OBJECT

public:
    explicit AddGroup(QString, Chatlist *);
    ~AddGroup();

private slots:
    void on_cancelButton_clicked();

    void on_joinButton_clicked();

private:
    Ui::AddGroup *ui;
    QString userName;
    Chatlist *m_chat;
};

#endif // ADDGROUP_H
