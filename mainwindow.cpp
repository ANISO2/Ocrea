#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenements.h"
#include <QMessageBox>
#include <QtDebug>
#include<QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}






void MainWindow::on_pushButton_event_clicked()
{

    QString idevenement=ui->leidevenement->text();
    QString nomevenement=ui->lenomevenement->text();
    QDateTime datedebut=ui->dateTimeEdit_event->dateTime();
    QString duree=ui->leduree->text();
    QString urlvideo=ui->leurlvideo->text();

    evenements e(idevenement,nomevenement,datedebut,duree,urlvideo);
    bool test=e.ajouter_evenements();

    if (test)
    {
        ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement->clear();
        ui->lenomevenement->clear();
        ui->dateTimeEdit_event->setDateTime(QDateTime::currentDateTime());
        ui->leduree->clear();
        ui->leurlvideo->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString idevenement=ui->leidevenement_supp->text();
    bool test=e.supprimer(idevenement);
    if(test)
    {
         ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supression effectue\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement_supp->clear();

    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement_supp->clear();

    }
}






void MainWindow::on_pushButton_update_clicked()
{
    QString idevenement=ui->leidevenement->text();
    QString nomevenement=ui->lenomevenement->text();
    QDateTime datedebut=ui->dateTimeEdit_event->dateTime();
    QString duree=ui->leduree->text();
    QString urlvideo=ui->leurlvideo->text();

    evenements e(idevenement,nomevenement,datedebut,duree,urlvideo);
    bool test=e.update(idevenement);

    if (test)
    {
        ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement->clear();
        ui->lenomevenement->clear();
        ui->dateTimeEdit_event->setDateTime(QDateTime::currentDateTime());
        ui->leduree->clear();
        ui->leurlvideo->clear();
    }
    else
    {

        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->leidevenement->clear();
        ui->lenomevenement->clear();
        ui->dateTimeEdit_event->setDateTime(QDateTime::currentDateTime());
        ui->leduree->clear();
        ui->leurlvideo->clear();
    }
}
