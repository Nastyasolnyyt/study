#include "begin.h"
#include "mainwindow.h"
#include "ui_begin.h"
#include "QSqlError"
#include "QMessageBox"
#include "QDebug"
#include "QSqlDriver"
#include "QApplication"
#include "Qfile"
#include "QSqlQuery"
#include "QFileDialog"
#include "QStringConverter"
#include "qsqlrecord.h"

begin::begin(QWidget *parent) : QWidget(parent), ui(new Ui::begin)
{
    ui->setupUi(this);
    setFixedSize(841, 573);


}

void begin::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/prilozhenie2/Frame 3 (6).png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    QWidget::resizeEvent(evt);
}

void begin::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Ошибка базы данных",
                          "Ошибка: " + err.text() +
                              "\nКод: " + err.nativeErrorCode() +
                              "\nДетали: " + err.databaseText());
}

void begin::on_pushButton_on_clicked()
{
    // Удаляем старую модель (если была)
    if (model) {
        delete model;
        model = nullptr;
    }

    // Закрываем предыдущее подключение (если было)
    if (m_db.isOpen()) {
        QString connectionName = m_db.connectionName();
        m_db.close();
        QSqlDatabase::removeDatabase(connectionName);
    }

    // Создаем новое подключение с уникальным именем
    QString connectionName = QString("PG_CONN_%1").arg(quintptr(this));
    m_db = QSqlDatabase::addDatabase("QPSQL", connectionName);

    // Получаем значения из полей ввода
    QString dbName = ui->databaseEdit->text().trimmed();
    QString userName = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();

    // Проверка обязательных полей
    if (dbName.isEmpty() || userName.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля для подключения");
        return;
    }

    m_db.setDatabaseName(dbName);
    m_db.setUserName(userName);
    m_db.setPassword(password);

    // Пробуем подключиться
    if (!m_db.open()) {
        showError(m_db.lastError());
        return;
    }

    // Создаем новую модель для таблицы
    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);

    QMessageBox::information(this, "Успех", "Подключение установлено!");
}


void begin::on_pushButton_do_clicked()
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

   // ui->tableView->resizeColumnsToContents();
}

begin::~begin()
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





void begin::on_backButton_clicked()
{   MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Закрываем текущее окно
    this->close();

}

void begin::exportTableToCSV(const QString &queryStr, const QString &dirPath)
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

void begin::on_backup_clicked()
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
