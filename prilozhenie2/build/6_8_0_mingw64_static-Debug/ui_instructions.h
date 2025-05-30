/********************************************************************************
** Form generated from reading UI file 'instructions.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONS_H
#define UI_INSTRUCTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_instructions
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *instructions)
    {
        if (instructions->objectName().isEmpty())
            instructions->setObjectName("instructions");
        instructions->resize(841, 583);
        instructions->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(instructions);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 170, 311, 81));

        retranslateUi(instructions);

        QMetaObject::connectSlotsByName(instructions);
    } // setupUi

    void retranslateUi(QWidget *instructions)
    {
        instructions->setWindowTitle(QCoreApplication::translate("instructions", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("instructions", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instructions: public Ui_instructions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONS_H
