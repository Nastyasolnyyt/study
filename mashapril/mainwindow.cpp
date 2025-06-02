#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>

// Загрузка шрифта


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    begwin = new dbwindow();
    instr = new spravka();    // Создаем объект второго окна
    this->setFixedSize(660, 660);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

void MainWindow::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/mashapril/Frame 24.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    QMainWindow::resizeEvent(evt);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete begwin;
    // Не забываем освободить память
}

void MainWindow::on_pushButton_2_clicked()
{
    begwin->show(); // Показываем второе окно
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    instr->show();
    this->close();
}

