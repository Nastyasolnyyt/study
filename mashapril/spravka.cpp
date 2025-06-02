#include "spravka.h"
#include "ui_spravka.h"
#include "mainwindow.h"

spravka::spravka(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::spravka)
{
    ui->setupUi(this);
    setFixedSize(660, 660);
}

spravka::~spravka()
{
    delete ui;
}

void spravka::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd("C:/server/mashapril/Frame 24.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    QWidget::resizeEvent(evt);
}


void spravka::on_pushButton_clicked()
{   MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Закрываем текущее окно
    this->close();

}

