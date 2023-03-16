#ifndef QDEBUG_H
#define QDEBUG_H
#include<QDebug>
#include <QDialog>

namespace Ui {
class Qdebug;
}

class Qdebug : public QDialog
{
    Q_OBJECT

public:
    explicit Qdebug(QWidget *parent = nullptr);
    ~Qdebug();

private:
    Ui::Qdebug *ui;
};

#endif // QDEBUG_H
