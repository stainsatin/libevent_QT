/********************************************************************************
** Form generated from reading UI file 'creategroup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUP_H
#define UI_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGroup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *createButton;

    void setupUi(QWidget *CreateGroup)
    {
        if (CreateGroup->objectName().isEmpty())
            CreateGroup->setObjectName("CreateGroup");
        CreateGroup->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateGroup);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CreateGroup);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(CreateGroup);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(CreateGroup);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        cancelButton = new QPushButton(CreateGroup);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);

        createButton = new QPushButton(CreateGroup);
        createButton->setObjectName("createButton");

        horizontalLayout_2->addWidget(createButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CreateGroup);

        QMetaObject::connectSlotsByName(CreateGroup);
    } // setupUi

    void retranslateUi(QWidget *CreateGroup)
    {
        CreateGroup->setWindowTitle(QCoreApplication::translate("CreateGroup", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateGroup", "<html><head/><body><p align=\"center\">\345\210\233\345\273\272\347\276\244\350\201\212</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("CreateGroup", "<html><head/><body><p align=\"center\">\347\276\244\345\220\215\347\247\260</p></body></html>", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateGroup", "\345\217\226\346\266\210", nullptr));
        createButton->setText(QCoreApplication::translate("CreateGroup", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroup: public Ui_CreateGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUP_H
