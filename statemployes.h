#ifndef STATEMPLOYES_H
#define STATEMPLOYES_H

#include <QWidget>

namespace Ui {
class statemployes;
}

class statemployes : public QWidget
{
    Q_OBJECT

public:
    explicit statemployes(QWidget *parent = nullptr);
    ~statemployes();

private:
    Ui::statemployes *ui;
};

#endif // STATEMPLOYES_H
