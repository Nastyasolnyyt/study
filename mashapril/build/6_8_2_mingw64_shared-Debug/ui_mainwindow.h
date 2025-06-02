/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(660, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 370, 172, 63));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  170px;\n"
"    max-width:  170px;\n"
"    min-height: 61px;\n"
"    max-height: 61px;\n"
"    font: 900 14pt \"Segoe UI\";\n"
"	background-color: #A8C17C;\n"
"	border-radius:15px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 440, 172, 63));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  170px;\n"
"    max-width:  170px;\n"
"    min-height: 61px;\n"
"    max-height: 61px;\n"
"    font: 900 14pt \"Segoe UI\";\n"
"	background-color: #EAAA57;\n"
"	border-radius:15px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 660, 660, 20));
        label->setPixmap(QPixmap(QString::fromUtf8("Frame 24.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 660, 660));
        label_2->setPixmap(QPixmap(QString::fromUtf8("Frame 24.png")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        label->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 660, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
