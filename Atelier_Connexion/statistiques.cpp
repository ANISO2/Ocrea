#include "statistiques.h"
#include "ui_statistiques.h"
#include <QPainter>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);

}
void statistiques::paintEvent(QPaintEvent *)
{

}
statistiques::~statistiques()
{
    delete ui;
}

void statistiques::on_pushButton11_clicked()
{
    close();
}
