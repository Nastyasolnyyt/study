#include "dbwindow.h"
#include "mainwindow.h"
#include "ui_dbwindow.h"
#include "QtSql/QSqlError"
#include "QMessageBox"
#include "QDebug"
#include "QtSql/QSqlDriver"
#include "QApplication"
#include "Qfile"
#include "QtSql/QSqlQuery"
#include "QFileDialog"
#include "QStringConverter"
#include "QtSql/QSqlRecord"
#include "QToolButton"
dbwindow::dbwindow(QWidget *parent) : QWidget(parent), ui(new Ui::dbwindow)
{
    ui->setupUi(this);
    setFixedSize(660,660);


}
/*void begin::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/bdpril/Frame 5 (5).png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    Qbegin::resizeEvent(evt);
    QWidget::resizeEvent(evt); // Важно: вызываем родительский метод

    // Загрузка и масштабирование фонового изображения
    QPixmap bkgnd("C:/server/bdpril/Frame 3 (6).png");
    if(!bkgnd.isNull()) {
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
    }
}
*/
void dbwindow::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/mashapril/Frame 25 (1).png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    QWidget::resizeEvent(evt);
}

void dbwindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Ошибка базы данных",
                          "Ошибка: " + err.text() +
                              "\nКод: " + err.nativeErrorCode() +
                              "\nДетали: " + err.databaseText());
}

void dbwindow::on_pushButton_on_clicked()

{

    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);

    ui->databaseEdit->setText("masha");
    ui->usernameEdit->setText("postgres");
    ui->passwordEdit->setText("postgres");
    if (m_db.isOpen()) {
        QString connectionName = m_db.connectionName();
        m_db.close();
        QSqlDatabase::removeDatabase(connectionName);
    }

    QString connectionName = QString("PG_CONN_%1").arg(quintptr(this));
    m_db = QSqlDatabase::addDatabase("QPSQL", connectionName);
    m_db.setDatabaseName(ui->databaseEdit->text());
    m_db.setUserName(ui->usernameEdit->text());
    m_db.setPassword(ui->passwordEdit->text());

    if (!m_db.open()) {
        showError(m_db.lastError());
        return;
    }

    QMessageBox::information(this, "Успех", "Подключение установлено!");
}


void dbwindow::on_pushButton_do_clicked()
{
    if (!m_db.isOpen()) {
        QMessageBox::warning(this, "Ошибка", "Сначала подключитесь к базе данных!");
        return;
    }

    QString queryText = ui->queryEdit->toPlainText().trimmed();
    if (queryText.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите SQL-запрос!");
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    model->setQuery(queryText, m_db);
    QApplication::restoreOverrideCursor();

    if (model->lastError().isValid()) {
        showError(model->lastError());
        return;
    }

    ui->tableView->resizeColumnsToContents();
}

void dbwindow::on_backButton_clicked()
{   MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Закрываем текущее окно
    this->close();

}

void dbwindow::exportTableToCSV(const QString &queryStr, const QString &dirPath)
{
    QSqlQuery query(m_db);
    if (!query.exec(queryStr)) {
        showError(query.lastError());
        return;
    }

    if (!query.isActive()) {
        QMessageBox::warning(this, "Ошибка", "Запрос не вернул результатов");
        return;
    }

    QFile file(dirPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось создать файл: " + dirPath);
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    // Записываем заголовки
    QSqlRecord record = query.record();
    for (int i = 0; i < record.count(); ++i) {
        if (i > 0) out << ",";
        out << "\"" << record.fieldName(i) << "\"";
    }
    out << "\n";

    // Записываем данные
    while (query.next()) {
        for (int i = 0; i < record.count(); ++i) {
            if (i > 0) out << ",";
            out << "\"" << query.value(i).toString() << "\"";
        }
        out << "\n";
    }

    file.close();
}

void dbwindow::on_backup_clicked()
{
    if (!m_db.isOpen()) {
        QMessageBox::warning(this, "Ошибка", "Сначала подключитесь к базе данных!");
        return;
    }

    // Получите SQL-запрос из QTextEdit
    QString queryStr = ui->queryEdit->toPlainText().trimmed();

    if (queryStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите SQL-запрос");
        return;
    }

    // Запрос на выбор места и имени файла для сохранения
    QString saveFilePath = QFileDialog::getSaveFileName(this, "Сохранить как", QDir::homePath(),
                                                        "CSV Files (*.csv);;All Files (*)");
    if (saveFilePath.isEmpty()) return;

    // Экспорт результата запроса в выбранный файл
    exportTableToCSV(queryStr, saveFilePath);

    QMessageBox::information(this, "Готово", "Экспорт результата запроса завершен!");
}


dbwindow::~dbwindow()
{
    if (m_db.isOpen()) {
        QString connectionName = m_db.connectionName();
        m_db.close();
        QSqlDatabase::removeDatabase(connectionName);
    }
    QApplication::quit();
    exit(0);
    delete ui;
}













