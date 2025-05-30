#include "mainwindow.h"
#include "begin.h"
#include "instructions.h"
#include <QApplication>

int main(int argc, char *argv[])
{   QApplication a(argc, argv);
    qDebug() << "Application started";
    MainWindow w;
    w.show();
    int ret = a.exec();
    qDebug() << "Application exited with code:" << ret;
    return ret;
}
