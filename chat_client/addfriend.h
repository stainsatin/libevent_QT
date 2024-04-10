#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include "chatlist.h"

namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(QString, Chatlist *);
    ~AddFriend();

private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::AddFriend *ui;
    QString userName;
    Chatlist *m_parent;
};

#endif // ADDFRIEND_H
