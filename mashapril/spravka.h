#ifndef SPRAVKA_H
#define SPRAVKA_H

/*class spravka
{
public:
    spravka();
};
*/
#include "QWidget"

namespace Ui {
class spravka;
}

class spravka : public QWidget
{
    Q_OBJECT

public:
    explicit spravka(QWidget *parent = nullptr);
    ~spravka();
    void resizeEvent(QResizeEvent *evt);



private slots:
    void on_pushButton_clicked();

private:
    Ui::spravka *ui;
};


#endif // SPRAVKA_H
