#ifndef BEGIN_H
#define BEGIN_H

#include "qsqlerror.h"
#include "ui_begin.h"
#include "QWidget"
#include "QMainWindow"
#include "QSqlDatabase"
#include "QSqlQueryModel"
#include "QMessageBox"

class begin : public QWidget
{
    Q_OBJECT
public:
    explicit begin(QWidget *parent = nullptr);
    ~begin();
    void resizeEvent(QResizeEvent *evt);
    void exportTableToCSV(const QString &tableName, const QString &dirPath);


private slots:

    void on_pushButton_on_clicked();

    void on_pushButton_do_clicked();



    void on_backButton_clicked();

    void on_backup_clicked();

private:
    void showError(const QSqlError &err);
    void setupDatabase();
    Ui::begin *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *model;



};

#endif // BEGIN_H
