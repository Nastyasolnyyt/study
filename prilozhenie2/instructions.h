#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>

namespace Ui {
class instructions;
}

class instructions : public QWidget
{
    Q_OBJECT

public:
    explicit instructions(QWidget *parent = nullptr);
    ~instructions();
    void resizeEvent(QResizeEvent *evt);



private slots:
    void on_pushButton_clicked();

private:
    Ui::instructions *ui;
};

#endif // INSTRUCTIONS_H
