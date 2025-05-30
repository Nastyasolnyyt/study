/********************************************************************************
** Form generated from reading UI file 'begin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEGIN_H
#define UI_BEGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_begin
{
public:
    QTextEdit *queryEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_on;
    QPushButton *pushButton_do;
    QPushButton *backup;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *databaseEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QTableView *tableView;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *backButton;

    void setupUi(QWidget *begin)
    {
        if (begin->objectName().isEmpty())
            begin->setObjectName("begin");
        begin->resize(841, 583);
        queryEdit = new QTextEdit(begin);
        queryEdit->setObjectName("queryEdit");
        queryEdit->setGeometry(QRect(10, 240, 821, 81));
        verticalLayoutWidget = new QWidget(begin);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(460, 70, 211, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_on = new QPushButton(verticalLayoutWidget);
        pushButton_on->setObjectName("pushButton_on");
        pushButton_on->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  180px;\n"
"    max-width:  180px;\n"
"    min-height: 35px;\n"
"    max-height: 35px;\n"
"    font: 900 12pt \"Segoe UI\";\n"
"	background-color: #000000;\n"
"	border-radius:15px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_on);

        pushButton_do = new QPushButton(verticalLayoutWidget);
        pushButton_do->setObjectName("pushButton_do");
        pushButton_do->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  180px;\n"
"    max-width:  180px;\n"
"    min-height: 35px;\n"
"    max-height: 35px;\n"
"    font: 900 12pt \"Segoe UI\";\n"
"	background-color: #000000;\n"
"	border-radius:15px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_do);

        backup = new QPushButton(verticalLayoutWidget);
        backup->setObjectName("backup");
        backup->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: #ffffff;\n"
"	min-width:  180px;\n"
"    max-width:  180px;\n"
"    min-height: 35px;\n"
"    max-height: 35px;\n"
"    font: 900 12pt \"Segoe UI\";\n"
"	background-color: #000000;\n"
"	border-radius:15px;\n"
"	border: 1px solid #ccc;\n"
"}\n"
" QPushButton:hover{\n"
"	background-color:#676767;\n"
"	\n"
"}\n"
""));

        verticalLayout->addWidget(backup);

        verticalLayoutWidget_2 = new QWidget(begin);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(20, 60, 181, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        databaseEdit = new QLineEdit(verticalLayoutWidget_2);
        databaseEdit->setObjectName("databaseEdit");

        verticalLayout_2->addWidget(databaseEdit);

        usernameEdit = new QLineEdit(verticalLayoutWidget_2);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout_2->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(verticalLayoutWidget_2);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout_2->addWidget(passwordEdit);

        tableView = new QTableView(begin);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 330, 821, 241));
        verticalLayoutWidget_3 = new QWidget(begin);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(210, 70, 231, 141));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 700 12pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(label_2);

        backButton = new QPushButton(begin);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(30, 20, 92, 22));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(begin);

        QMetaObject::connectSlotsByName(begin);
    } // setupUi

    void retranslateUi(QWidget *begin)
    {
        begin->setWindowTitle(QCoreApplication::translate("begin", "Form2", nullptr));
        pushButton_on->setText(QCoreApplication::translate("begin", "\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        pushButton_do->setText(QCoreApplication::translate("begin", "\320\262\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\267\320\260\320\277\321\200\320\276\321\201", nullptr));
        backup->setText(QCoreApplication::translate("begin", "\321\201\320\272\320\260\321\207\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("begin", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_3->setText(QCoreApplication::translate("begin", "\320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("begin", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
#if QT_CONFIG(whatsthis)
        backButton->setWhatsThis(QCoreApplication::translate("begin", "<html><head/><body><p>\320\275\320\260\320\267\320\260\320\264</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        backButton->setText(QCoreApplication::translate("begin", "\360\237\240\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class begin: public Ui_begin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEGIN_H
