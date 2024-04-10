/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chatlist
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *friendList;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *groupList;
    QPushButton *addButton;
    QPushButton *createButton;
    QPushButton *joinButton;

    void setupUi(QWidget *Chatlist)
    {
        if (Chatlist->objectName().isEmpty())
            Chatlist->setObjectName("Chatlist");
        Chatlist->resize(480, 640);
        verticalLayout = new QVBoxLayout(Chatlist);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(Chatlist);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        friendList = new QListWidget(tab);
        friendList->setObjectName("friendList");

        verticalLayout_2->addWidget(friendList);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupList = new QListWidget(tab_2);
        groupList->setObjectName("groupList");

        verticalLayout_3->addWidget(groupList);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        addButton = new QPushButton(Chatlist);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        createButton = new QPushButton(Chatlist);
        createButton->setObjectName("createButton");

        verticalLayout->addWidget(createButton);

        joinButton = new QPushButton(Chatlist);
        joinButton->setObjectName("joinButton");

        verticalLayout->addWidget(joinButton);


        retranslateUi(Chatlist);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chatlist);
    } // setupUi

    void retranslateUi(QWidget *Chatlist)
    {
        Chatlist->setWindowTitle(QCoreApplication::translate("Chatlist", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Chatlist", "\345\245\275\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Chatlist", "\347\276\244", nullptr));
        addButton->setText(QCoreApplication::translate("Chatlist", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        createButton->setText(QCoreApplication::translate("Chatlist", "\345\210\233\345\273\272\347\276\244\350\201\212", nullptr));
        joinButton->setText(QCoreApplication::translate("Chatlist", "\346\267\273\345\212\240\347\276\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chatlist: public Ui_Chatlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
