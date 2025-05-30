#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "begin.h"
#include "instructions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *evt);

private slots:
    void on_pushButton_2_clicked(); // Слот для кнопки "Начать"

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    begin *begwin;
    instructions *instr;    // Указатель на второе окно
};
#endif // MAINWINDOW_H
