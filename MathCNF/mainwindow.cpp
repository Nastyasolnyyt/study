#include "mainwindow.h"
#include "cnfconverter.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    inputLineEdit = new QLineEdit(this);
    inputLineEdit->setPlaceholderText("Введите логическое выражение -> ! & | =");

    convertButton = new QPushButton("Преобразовать в КНФ", this);
    connect(convertButton, &QPushButton::clicked, this, &MainWindow::convertToCNF);

    resultLabel = new QLabel("Результат будет отображен здесь", this);
    resultLabel->setWordWrap(true);

    layout->addWidget(inputLineEdit);
    layout->addWidget(convertButton);
    layout->addWidget(resultLabel);

    setCentralWidget(centralWidget);
    setWindowTitle("Конвертер в КНФ");
    resize(500, 200);
}

MainWindow::~MainWindow() {}

void MainWindow::convertToCNF()
{
    QString input = inputLineEdit->text().trimmed();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите выражение");
        return;
    }

    // Заменяем символы для корректной обработки
    input.replace("→", ">").replace("∧", "&").replace("∨", "|").replace("¬", "!");

    CNFConverter converter;
    std::string result = converter.convertToCNF(input.toStdString());

    // Форматируем вывод для лучшей читаемости
    QString output = QString::fromStdString(result)
                         .replace("&", " ∧ ")
                         .replace("|", " ∨ ")
                         .replace("!", "¬");

    resultLabel->setText(output);
}
