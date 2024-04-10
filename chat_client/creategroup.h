#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QWidget>
#include "chatlist.h"

namespace Ui {
class CreateGroup;
}

class CreateGroup : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroup(QString, Chatlist *);
    ~CreateGroup();

private slots:
    void on_cancelButton_clicked();

    void on_createButton_clicked();

private:
    Ui::CreateGroup *ui;
    QString userName;
    Chatlist *m_chat;
};

#endif // CREATEGROUP_H
