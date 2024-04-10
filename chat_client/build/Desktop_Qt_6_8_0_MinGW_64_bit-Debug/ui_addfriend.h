/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriend
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userEdit;
    QPushButton *cancelButton;
    QPushButton *addButton;

    void setupUi(QWidget *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName("AddFriend");
        AddFriend->resize(400, 300);
        label = new QLabel(AddFriend);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 40, 181, 41));
        label_2 = new QLabel(AddFriend);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 91, 41));
        userEdit = new QLineEdit(AddFriend);
        userEdit->setObjectName("userEdit");
        userEdit->setGeometry(QRect(130, 110, 211, 41));
        cancelButton = new QPushButton(AddFriend);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(70, 210, 111, 41));
        addButton = new QPushButton(AddFriend);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(240, 210, 111, 41));

        retranslateUi(AddFriend);

        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QWidget *AddFriend)
    {
        AddFriend->setWindowTitle(QCoreApplication::translate("AddFriend", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddFriend", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\346\267\273\345\212\240\345\245\275\345\217\213</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AddFriend", "<html><head/><body><p align=\"center\">\350\264\246\345\217\267</p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddFriend", "\345\217\226\346\266\210", nullptr));
        addButton->setText(QCoreApplication::translate("AddFriend", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
