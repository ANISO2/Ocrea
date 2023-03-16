#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QMovie>
#include <QtGui>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "voiture.h"
#include <QMessageBox>
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher_voiture());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_8_clicked()
{
QString cin=ui->lineEditcin->text();
QString nomvoiture=ui->lineEditnomvoiture->text();
QString prenomvoiture=ui->lineEditprenomvoiture->text();
QString matriculevoiture=ui->lineEditmatriculevoiture->text();

voiture v(cin,nomvoiture,prenomvoiture,matriculevoiture);
bool test=v.ajouter_voiture();
if (test)
{
    ui->tableView->setModel(Etmp.afficher_voiture());
    ui->lineEditcin->clear();
    ui->lineEditnomvoiture->clear();
    ui->lineEditprenomvoiture->clear();
    ui->lineEditmatriculevoiture->clear();

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);

}
else
{

    ui->lineEditcin->clear();
    ui->lineEditnomvoiture->clear();
    ui->lineEditprenomvoiture->clear();
    ui->lineEditmatriculevoiture->clear();
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
}
}


void MainWindow::on_pushButton_10_clicked()
{
    QString cin=ui->lineEdit_suppri->text();
    bool test=Etmp.supprimer_voiture(cin);


    if (test)
    {
        ui->tableView->setModel(Etmp.afficher_voiture());
        ui->lineEdit_suppri->clear();

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {

              ui->lineEdit_suppri->clear();
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Suppression non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
}






void MainWindow::on_pushButton_9_clicked()
{
    QString cin=ui->lineEditcin->text();
    QString nomvoiture=ui->lineEditnomvoiture->text();
    QString prenomvoiture=ui->lineEditprenomvoiture->text();
    QString matriculevoiture=ui->lineEditmatriculevoiture->text();


    voiture v(cin,nomvoiture,prenomvoiture,matriculevoiture);
    bool test=v.update(cin);

    if (test)
    {
        ui->tableView->setModel(v.afficher_voiture());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->lineEditcin->clear();
        ui->lineEditnomvoiture->clear();
        ui->lineEditprenomvoiture->clear();
        ui->lineEditmatriculevoiture->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->lineEditcin->clear();
        ui->lineEditnomvoiture->clear();
        ui->lineEditprenomvoiture->clear();
        ui->lineEditmatriculevoiture->clear();
    }
}
