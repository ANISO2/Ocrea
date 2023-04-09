#include "statemployes.h"
#include "ui_statemployes.h"

statemployes::statemployes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statemployes)
{
    ui->setupUi(this);
}

statemployes::~statemployes()
{
    delete ui;
}
