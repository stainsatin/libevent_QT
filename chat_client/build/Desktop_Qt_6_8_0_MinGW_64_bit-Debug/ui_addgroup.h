/********************************************************************************
** Form generated from reading UI file 'addgroup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUP_H
#define UI_ADDGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGroup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *joinButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *AddGroup)
    {
        if (AddGroup->objectName().isEmpty())
            AddGroup->setObjectName("AddGroup");
        AddGroup->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddGroup);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddGroup);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(AddGroup);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(AddGroup);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        joinButton = new QPushButton(AddGroup);
        joinButton->setObjectName("joinButton");

        verticalLayout->addWidget(joinButton);

        cancelButton = new QPushButton(AddGroup);
        cancelButton->setObjectName("cancelButton");

        verticalLayout->addWidget(cancelButton);


        retranslateUi(AddGroup);

        QMetaObject::connectSlotsByName(AddGroup);
    } // setupUi

    void retranslateUi(QWidget *AddGroup)
    {
        AddGroup->setWindowTitle(QCoreApplication::translate("AddGroup", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddGroup", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\345\212\240\345\205\245\347\276\244\350\201\212</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AddGroup", "<html><head/><body><p align=\"center\">\347\276\244\345\220\215\347\247\260</p></body></html>", nullptr));
        joinButton->setText(QCoreApplication::translate("AddGroup", "\345\212\240\345\205\245", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddGroup", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroup: public Ui_AddGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUP_H
