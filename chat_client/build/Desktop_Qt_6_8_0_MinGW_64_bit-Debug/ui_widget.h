/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *userEdit;
    QLineEdit *passWordEdit;
    QPushButton *registerButton;
    QPushButton *loginButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(411, 313);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 40, 111, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 111, 31));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 150, 111, 31));
        userEdit = new QLineEdit(Widget);
        userEdit->setObjectName("userEdit");
        userEdit->setGeometry(QRect(140, 100, 181, 31));
        passWordEdit = new QLineEdit(Widget);
        passWordEdit->setObjectName("passWordEdit");
        passWordEdit->setGeometry(QRect(140, 150, 181, 31));
        registerButton = new QPushButton(Widget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(70, 230, 91, 41));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(250, 230, 91, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\350\277\234\347\250\213\351\200\232\344\277\241</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\347\224\250\346\210\267\345\220\215</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\257\206\347\240\201</p></body></html>", nullptr));
        userEdit->setText(QCoreApplication::translate("Widget", "tom", nullptr));
        passWordEdit->setText(QCoreApplication::translate("Widget", "11111", nullptr));
        registerButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        loginButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
