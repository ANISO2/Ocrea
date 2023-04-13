#include "voiture.h"
#include "QRegularExpression"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>
#include <QSqlError>
#include <QChartView>
#include <regex>



voiture::voiture(QString cin,QString nomvoiture,QString prenomvoiture,QString matriculevoiture,QString IDBATTERIE)
{
  this->cin=cin;
   this->nomvoiture=nomvoiture;
    this->prenomvoiture=prenomvoiture;
    this->matriculevoiture=matriculevoiture;
      this->IDBATTERIE=IDBATTERIE;
}

QSqlQueryModel * voiture::afficher_voiture()
{
    QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT * FROM VOITURES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomvoiture"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenomvoiture"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("matriculevoiture"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("IDBATTERIE"));
return model;


}


bool voiture::ajouter_voiture()
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$"); // Expression régulière pour vérifier si une chaîne de caractères contient uniquement des lettres

    if (!regex.match(cin).hasMatch() || cin.length() > 8 ) {
        // Vérifier si le CIN est un nombre et si les champs ne dépassent pas les limites
       QMessageBox::warning(0,"Erreur","le CIN est un nombre et  ne dépassent pas 8 chiffres");
        return false;
    }
    if (!letterRegex.match(nomvoiture).hasMatch()) {
        // Vérifier si NOMVOITURE contient uniquement des lettres
        QMessageBox::warning(0,"Erreur","le NOMVOITURE doit etre des alphabet");
        return false;
    }
    if (!letterRegex.match(prenomvoiture).hasMatch()) {
        // Vérifier si PRENOMVOITURE contient uniquement des lettres
        QMessageBox::warning(0,"Erreur","le PRENOMVOITURE doit etre des alphabet");
        return false;
    }
    if (!matriculevoiture.contains("TUN") && !matriculevoiture.contains("DUBAI"))  {
        // Vérifier si MATRICULEVOITURE contient le mot "TUN"
        QMessageBox::warning(0,"Erreur"," TUN ou DUBAI doit etre inclu dans MATRICULEVOITURE");
        return false;
    }

    query.prepare("INSERT INTO VOITURES (CIN,NOMVOITURE,PRENOMVOITURE,MATRICULEVOITURE,IDBATTERIE) values(:cin,:nomvoiture,:prenomvoiture,:matriculevoiture,:IDBATTERIE)");

    query.bindValue(":cin",cin);
    query.bindValue(":nomvoiture",nomvoiture.left(10)); // Tronquer le champ NOMVOITURE à 10 caractères maximum
    query.bindValue(":prenomvoiture",prenomvoiture.left(10)); // Tronquer le champ PRENOMVOITURE à 10 caractères maximum
    query.bindValue(":matriculevoiture",matriculevoiture.left(10)); // Tronquer le champ MATRICULEVOITURE à 10 caractères maximum
    query.bindValue(":IDBATTERIE",IDBATTERIE.left(10));
    return query.exec();
}



bool voiture::supprimer_voiture(QString cin)
{
    QSqlQuery query;
    if(cin.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ cin est vide!");

                return false;}
    if (!verifiercin(cin)) {
        QMessageBox::warning(0, "Erreur", "Le cin de voiture n'existe pas!");
        return false;}

    QString res = QString(cin);

    QMessageBox::StandardButton reply = QMessageBox::question(
                nullptr,
                "Confirmation de suppression",
                "Êtes-vous sûr de vouloir supprimer cette voiture ?",
                QMessageBox::Yes | QMessageBox::No
                );

    if (reply == QMessageBox::Yes) {
        query.prepare("DELETE FROM VOITURES WHERE cin= :cin");
        query.bindValue(":cin",res);
        return query.exec();
    } else {
        return false;

}
    }

bool voiture::update(QString cin)
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$"); // Expression régulière pour vérifier si une chaîne de caractères contient uniquement des lettres

    if (!regex.match(cin).hasMatch() || cin.length() > 8 ) {
        // Vérifier si le CIN est un nombre et si les champs ne dépassent pas les limites
        return false;
    }
    if (!letterRegex.match(nomvoiture).hasMatch()) {
        // Vérifier si NOMVOITURE contient uniquement des lettres
        return false;
    }
    if (!letterRegex.match(prenomvoiture).hasMatch()) {
        // Vérifier si PRENOMVOITURE contient uniquement des lettres
        return false;
    }

    if (!matriculevoiture.contains("TUN")) {
        // Vérifier si MATRICULEVOITURE contient le mot "TUN"
        return false;
    }

    if(cin.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ cin est vide!");

                return false;}
    if (!verifiercin(cin)) {
           QMessageBox::warning(0, "Erreur", "Le cin de voiture n'existe pas!");
           return false;}

    //Prepare the query
    query.prepare("UPDATE voitures SET cin=:cin, nomvoiture=:nomvoiture,prenomvoiture=:prenomvoiture,matriculevoiture=:matriculevoiture WHERE cin=:cin;");


    //Bind the values
    query.bindValue(":cin",cin);
    query.bindValue(":nomvoiture",nomvoiture);
    query.bindValue(":prenomvoiture",prenomvoiture);
    query.bindValue(":matriculevoiture",matriculevoiture);


    return query.exec();
}

bool voiture::verifiercin(QString cin) {
    QSqlQuery query;
    query.prepare("SELECT cin FROM voitures WHERE cin = :cin");
    query.bindValue(":cin", cin);
    if (query.exec() && query.next()) {

        // cin existe déjà
        return true;
    }
    // cin n'existe pas encore
    return false;
}

/*QSqlQueryModel* voiture::rechercher_cin(QString cin)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    QSqlQuery query;
    if(cin.isEmpty())
             QMessageBox::warning(0, "Erreur", "Le champ est vide!");
    if (!verifiercin(cin)) {
           QMessageBox::warning(0, "Erreur", "Le cin n'existe pas!");
           }

    query.prepare("SELECT * FROM VOITURES WHERE cin LIKE :cin ");
    query.bindValue(":cin","%"+cin+"%");
    query.exec();
    model->setQuery(query);
    return model;
}
*/

QSqlQueryModel* voiture::tri_cin()

{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM voitures ORDER BY cin DESC");
    return model;
}

QChartView *voiture::statistique()
{
    int stat=0;
    int Statii=0;


    QSqlQuery query;
    query.prepare("select * from VOITURES where MATRICULEVOITURE LIKE '%DUBAI%'");
    query.exec();
    while(query.next())
       stat++;

    query.prepare("select * from VOITURES where MATRICULEVOITURE LIKE '%TUN%'");
    query.exec();
    while(query.next())
        Statii++;

     qDebug() <<stat << Statii  ;

     QPieSeries *series = new QPieSeries();
         series->append("DUBAI",stat);
         series->append("TUN",Statii);

         // calculer le total des données
         int total = stat + Statii;

         // ajouter des étiquettes avec des pourcentages
         QString labelDubai = QString("DUBAI (%1%)").arg((double)stat/total * 100, 0, 'f', 1);
         QString labelTun = QString("TUN (%1%)").arg((double)Statii/total * 100, 0, 'f', 1);
         series->slices().at(0)->setLabel(labelDubai);
         series->slices().at(1)->setLabel(labelTun);

         QPieSlice *slice = series->slices().at(0);
         slice->setExploded(true);
         slice->setColor("#55BBAB");
         QPieSlice *slice2 = series->slices().at(1);
         slice2->setColor("#22423C");

         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("Statistics");

         series->setLabelsVisible();

         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->chart()->setAnimationOptions(QChart::AllAnimations);
         chartView->chart()->legend()->hide();
         return chartView;
}
