/********************************************************************************
** Form generated from reading UI file 'dbwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWINDOW_H
#define UI_DBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dbwindow
{
public:
    QTableView *tableView;
    QTextEdit *queryEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *databaseEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *pushButton_on;
    QPushButton *pushButton_do;
    QPushButton *backup;
    QPushButton *backButton;

    void setupUi(QWidget *dbwindow)
    {
        if (dbwindow->objectName().isEmpty())
            dbwindow->setObjectName("dbwindow");
        dbwindow->resize(960, 960);
        tableView = new QTableView(dbwindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(390, 430, 531, 431));
        queryEdit = new QTextEdit(dbwindow);
        queryEdit->setObjectName("queryEdit");
        queryEdit->setGeometry(QRect(390, 320, 521, 75));
        verticalLayoutWidget = new QWidget(dbwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 120, 281, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        databaseEdit = new QLineEdit(verticalLayoutWidget);
        databaseEdit->setObjectName("databaseEdit");

        verticalLayout->addWidget(databaseEdit);

        usernameEdit = new QLineEdit(verticalLayoutWidget);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(verticalLayoutWidget);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout->addWidget(passwordEdit);

        pushButton_on = new QPushButton(dbwindow);
        pushButton_on->setObjectName("pushButton_on");
        pushButton_on->setGeometry(QRect(660, 50, 93, 29));
        pushButton_do = new QPushButton(dbwindow);
        pushButton_do->setObjectName("pushButton_do");
        pushButton_do->setGeometry(QRect(660, 100, 93, 29));
        backup = new QPushButton(dbwindow);
        backup->setObjectName("backup");
        backup->setGeometry(QRect(670, 150, 93, 29));
        backButton = new QPushButton(dbwindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 20, 93, 29));

        retranslateUi(dbwindow);

        QMetaObject::connectSlotsByName(dbwindow);
    } // setupUi

    void retranslateUi(QWidget *dbwindow)
    {
        dbwindow->setWindowTitle(QCoreApplication::translate("dbwindow", "Form", nullptr));
        pushButton_on->setText(QCoreApplication::translate("dbwindow", "PushButton", nullptr));
        pushButton_do->setText(QCoreApplication::translate("dbwindow", "PushButton", nullptr));
        backup->setText(QCoreApplication::translate("dbwindow", "PushButton", nullptr));
        backButton->setText(QCoreApplication::translate("dbwindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbwindow: public Ui_dbwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWINDOW_H
