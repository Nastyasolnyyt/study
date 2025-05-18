#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertToCNF();

private:
    QLineEdit *inputLineEdit;
    QLabel *resultLabel;
    QPushButton *convertButton;
};

#endif // MAINWINDOW_H
