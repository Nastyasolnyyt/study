/********************************************************************************
** Form generated from reading UI file 'instructions.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
        pushButton->setGeometry(QRect(30, 10, 92, 22));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  90px;\n"
"    max-width:  90px;\n"
"    min-height: 20px;\n"
"    max-height: 20px;\n"
"    font: 900 14pt \"Segoe UI\";\n"
"	background-color: #000000;\n"
"	border-radius:10px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));

        retranslateUi(instructions);

        QMetaObject::connectSlotsByName(instructions);
    } // setupUi

    void retranslateUi(QWidget *instructions)
    {
        instructions->setWindowTitle(QCoreApplication::translate("instructions", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("instructions", "\360\237\240\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instructions: public Ui_instructions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONS_H
