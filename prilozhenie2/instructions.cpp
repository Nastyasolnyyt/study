#include "instructions.h"
#include "ui_instructions.h"
#include "mainwindow.h"

instructions::instructions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::instructions)
{
    ui->setupUi(this);
    setFixedSize(841, 573);
}

instructions::~instructions()
{
    delete ui;
}

void instructions::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/prilozhenie2/Frame 7 (8).png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    QWidget::resizeEvent(evt);
}


void instructions::on_pushButton_clicked()
{   MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Закрываем текущее окно
    this->close();

}

