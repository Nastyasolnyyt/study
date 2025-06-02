/********************************************************************************
** Form generated from reading UI file 'dbwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWINDOW_H
#define UI_DBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QPushButton *backButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_do;
    QPushButton *backup;
    QPushButton *pushButton_on;
    QLabel *label;

    void setupUi(QWidget *dbwindow)
    {
        if (dbwindow->objectName().isEmpty())
            dbwindow->setObjectName("dbwindow");
        dbwindow->resize(1190, 660);
        tableView = new QTableView(dbwindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 390, 631, 261));
        queryEdit = new QTextEdit(dbwindow);
        queryEdit->setObjectName("queryEdit");
        queryEdit->setGeometry(QRect(260, 300, 381, 75));
        verticalLayoutWidget = new QWidget(dbwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 50, 201, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        databaseEdit = new QLineEdit(verticalLayoutWidget);
        databaseEdit->setObjectName("databaseEdit");
        databaseEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    color: #ffffff;               /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: #000000;    /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    border: 2px solid #555555;    /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 */\n"
"    border-radius: 15px;          /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px;                 /* \320\236\321\202\321\201\321\202\321\203\320\277 \320\262\320\275\321\203\321\202\321\200\320\270 */\n"
"    font: 900 12pt \"Segoe UI\";    /* \320\250\321\200\320\270\321\204\321\202 (\320\266\320\270\321\200\320\275\321\213\320\271, \321\200\320\260\320\267\320\274\320\265\321\200, \321\201\320\265\320\274\320\265\320\271\321\201\321\202\320\262\320\276) */\n"
"    min-width: 180px;             /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321"
                        "\214\320\275\320\260\321\217 \321\210\320\270\321\200\320\270\320\275\320\260 */\n"
"    min-height: 35px;             /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 */\n"
"    selection-color: #ff0000;     /* \320\246\320\262\320\265\321\202 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    selection-background-color: #00ff00; /* \320\244\320\276\320\275 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"QTextEdit:hover {\n"
"    border: 2px solid #888888;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203"
                        "\321\201\320\265 */\n"
"QTextEdit:focus {\n"
"    border: 2px solid #0078d7;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\264\320\273\321\217 \320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\275\320\276\320\263\320\276 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 */\n"
"QTextEdit:disabled {\n"
"    color: #aaaaaa;\n"
"    background-color: #333333;\n"
"}"));

        verticalLayout->addWidget(databaseEdit);

        usernameEdit = new QLineEdit(verticalLayoutWidget);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(verticalLayoutWidget);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout->addWidget(passwordEdit);

        backButton = new QPushButton(dbwindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(550, 10, 93, 29));
        horizontalLayoutWidget = new QWidget(dbwindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(270, 210, 371, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_do = new QPushButton(horizontalLayoutWidget);
        pushButton_do->setObjectName("pushButton_do");

        horizontalLayout->addWidget(pushButton_do);

        backup = new QPushButton(horizontalLayoutWidget);
        backup->setObjectName("backup");

        horizontalLayout->addWidget(backup);

        pushButton_on = new QPushButton(dbwindow);
        pushButton_on->setObjectName("pushButton_on");
        pushButton_on->setGeometry(QRect(40, 250, 181, 29));
        label = new QLabel(dbwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 660, 660));
        label->setPixmap(QPixmap(QString::fromUtf8("Frame 25 (1).png")));
        label->setScaledContents(true);
        label->raise();
        tableView->raise();
        queryEdit->raise();
        verticalLayoutWidget->raise();
        backButton->raise();
        horizontalLayoutWidget->raise();
        pushButton_on->raise();

        retranslateUi(dbwindow);

        QMetaObject::connectSlotsByName(dbwindow);
    } // setupUi

    void retranslateUi(QWidget *dbwindow)
    {
        dbwindow->setWindowTitle(QCoreApplication::translate("dbwindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("dbwindow", "\360\237\240\224", nullptr));
        pushButton_do->setText(QCoreApplication::translate("dbwindow", "\320\262\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        backup->setText(QCoreApplication::translate("dbwindow", "\321\201\320\272\320\260\321\207\320\260\321\202\321\214", nullptr));
        pushButton_on->setText(QCoreApplication::translate("dbwindow", "\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dbwindow: public Ui_dbwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWINDOW_H
