#ifndef DBWINDOW_H
#define DBWINDOW_H
#include "ui_dbwindow.h"
#include "QWidget"
#include "QMainWindow"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQueryModel"

class dbwindow : public QWidget
{
    Q_OBJECT
public:
    explicit dbwindow(QWidget *parent = nullptr);
    ~dbwindow();
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
    Ui::dbwindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *model;



};
#endif // DBWINDOW_H
