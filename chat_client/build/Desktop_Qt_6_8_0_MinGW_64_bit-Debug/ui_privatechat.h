/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrivateChat
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *fileButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *PrivateChat)
    {
        if (PrivateChat->objectName().isEmpty())
            PrivateChat->setObjectName("PrivateChat");
        PrivateChat->resize(400, 300);
        verticalLayout = new QVBoxLayout(PrivateChat);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(PrivateChat);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(PrivateChat);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        sendButton = new QPushButton(PrivateChat);
        sendButton->setObjectName("sendButton");

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fileButton = new QPushButton(PrivateChat);
        fileButton->setObjectName("fileButton");

        horizontalLayout_2->addWidget(fileButton);

        cancelButton = new QPushButton(PrivateChat);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PrivateChat);

        QMetaObject::connectSlotsByName(PrivateChat);
    } // setupUi

    void retranslateUi(QWidget *PrivateChat)
    {
        PrivateChat->setWindowTitle(QCoreApplication::translate("PrivateChat", "Form", nullptr));
        sendButton->setText(QCoreApplication::translate("PrivateChat", "\345\217\221\351\200\201", nullptr));
        fileButton->setText(QCoreApplication::translate("PrivateChat", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        cancelButton->setText(QCoreApplication::translate("PrivateChat", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrivateChat: public Ui_PrivateChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H
