#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    begwin = new begin();
    instr = new instructions();    // Создаем объект второго окна
    this->setFixedSize(841, 573);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowMaximizeButtonHint);
}

void MainWindow::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/prilozhenie2/Frame 5 (5).png");
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

