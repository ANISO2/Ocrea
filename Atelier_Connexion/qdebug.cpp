#include "qdebug.h"
#include "ui_qdebug.h"
#include<QDebug>
Qdebug::Qdebug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qdebug)
{
    ui->setupUi(this);
}

Qdebug::~Qdebug()
{
    delete ui;
}
