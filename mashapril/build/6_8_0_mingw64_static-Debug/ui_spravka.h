/********************************************************************************
** Form generated from reading UI file 'spravka.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRAVKA_H
#define UI_SPRAVKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_spravka
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *spravka)
    {
        if (spravka->objectName().isEmpty())
            spravka->setObjectName("spravka");
        spravka->resize(960, 960);
        pushButton = new QPushButton(spravka);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 93, 29));

        retranslateUi(spravka);

        QMetaObject::connectSlotsByName(spravka);
    } // setupUi

    void retranslateUi(QWidget *spravka)
    {
        spravka->setWindowTitle(QCoreApplication::translate("spravka", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("spravka", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class spravka: public Ui_spravka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRAVKA_H
