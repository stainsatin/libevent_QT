/********************************************************************************
** Form generated from reading UI file 'groupchat.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHAT_H
#define UI_GROUPCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupChat
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *GroupChat)
    {
        if (GroupChat->objectName().isEmpty())
            GroupChat->setObjectName("GroupChat");
        GroupChat->resize(400, 300);
        verticalLayout = new QVBoxLayout(GroupChat);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(GroupChat);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textEdit = new QTextEdit(GroupChat);
        textEdit->setObjectName("textEdit");

        horizontalLayout_2->addWidget(textEdit);

        listWidget = new QListWidget(GroupChat);
        listWidget->setObjectName("listWidget");

        horizontalLayout_2->addWidget(listWidget);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(GroupChat);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(GroupChat);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GroupChat);

        QMetaObject::connectSlotsByName(GroupChat);
    } // setupUi

    void retranslateUi(QWidget *GroupChat)
    {
        GroupChat->setWindowTitle(QCoreApplication::translate("GroupChat", "Form", nullptr));
        label->setText(QCoreApplication::translate("GroupChat", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("GroupChat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChat: public Ui_GroupChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHAT_H
