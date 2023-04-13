#include "evenements.h"
#include <QMessageBox>
#include "QRegularExpression"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>
#include <QSqlError>
#include <QChartView>

evenements::evenements(QString idevenement,QString nomevenement,QDateTime datedebut,QString duree,QString urlvideo)
{
  this->idevenement=idevenement;
   this->nomevenement=nomevenement;
    this->datedebut=datedebut;
    this->etat=duree;
    this->urlvideo=urlvideo;
}
bool evenements::ajouter_evenements()
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$");

    if (!regex.match(idevenement).hasMatch() || idevenement.length() > 5 ) {
        QMessageBox::warning(0, "Erreur", "id invalid!");

        return false;

    }
    if (!letterRegex.match(nomevenement).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "nom doit contient seulement des lettres alphabetiques!");

        return false;
    }

    if(etat != "termine" && etat != "en cours") {
        QMessageBox::warning(0, "Erreur de saisie", "L'état doit être soit 'termine' soit 'en cours'.");
        return false;
    }

    if (etat.contains(QRegularExpression("[^a-zA-Z0-9 ]"))) {
        QMessageBox::warning(0, "Erreur", "etat invalid!");

        return false;
    }

    if (!urlvideo.startsWith("C:")) {
        QMessageBox::warning(0, "Erreur", "url commence par C:!");

        return false;
    }

    query.prepare("INSERT INTO EVENEMENTS (IDEVENEMENT, NOMEVENEMENT, DATEDEBUT, ETAT, URLVIDEO)" "VALUES (:idevenement, :nomevenement, :datedebut, :etat, :urlvideo)");

    query.bindValue(":idevenement",idevenement);
    query.bindValue(":nomevenement",nomevenement);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":etat",etat);
    query.bindValue(":urlvideo",urlvideo);
    return query.exec();
}
QSqlQueryModel * evenements::afficher()
{

QSqlQueryModel * model=new  QSqlQueryModel();

model->setQuery("SELECT * FROM EVENEMENTS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("idevenement"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomevenement")),
model->setHeaderData(2,Qt::Horizontal,QObject::tr("datedebut"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("duree"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("urlvideo"));


return model;
}
bool evenements ::supprimer(QString idevenement)
{
    QSqlQuery query;
    if(idevenement.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ id est vide!");

                return false;}
    if (!verifierid(idevenement)) {
           QMessageBox::warning(0, "Erreur", "Lid  de levenement n'existe pas!");
           return false;}
    QString res = QString(idevenement);

        QMessageBox::StandardButton reply = QMessageBox::question(
                    nullptr,
                    "Confirmation de suppression",
                    "Êtes-vous sûr de vouloir supprimer cette evenements ?",
                    QMessageBox::Yes | QMessageBox::No
                    );

        if (reply == QMessageBox::Yes) {
            query.prepare("Delete from evenements where idevenement= :idevenement");
            query.bindValue(":idevenement",idevenement);
            return query.exec();
        } else {
            return false;
        }

    return query.exec();

}
bool evenements::update(QString idevenement)
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$");

    if (!regex.match(idevenement).hasMatch() || idevenement.length() > 5 ) {
        QMessageBox::warning(0, "Erreur", "id invalid!");

        return false;

    }
    if (!letterRegex.match(nomevenement).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "nom doit contient seulement des lettres alphabetiques!");

        return false;
    }
    if(etat != "termine" && etat != "en cours") {
        QMessageBox::warning(0, "Erreur de saisie", "L'état doit être soit 'termine' soit 'en cours'.");
        return false;
    }
    if (etat.contains(QRegularExpression("[^a-zA-Z0-9 ]"))) {
        QMessageBox::warning(0, "Erreur", "etat invalid!");

        return false;
    }

    if (!urlvideo.startsWith("C:")) {
        QMessageBox::warning(0, "Erreur", "url commence par c:!");

        return false;
    }
    //Prepare the query
    query.prepare("UPDATE evenements SET idevenement=:idevenement, nomevenement=:nomevenement,datedebut=:datedebut,etat=:etat,urlvideo=:urlvideo WHERE idevenement=:idevenement;");


    //Bind the values
    query.bindValue(":idevenement",idevenement);
    query.bindValue(":nomevenement",nomevenement);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":etat",etat);
    query.bindValue(":urlvideo",urlvideo);

    return query.exec();
}

bool evenements::verifierid(QString idevenement) {
    QSqlQuery query;
    query.prepare("SELECT idevenement FROM evenements WHERE idevenement = :idevenement");
    query.bindValue(":idevenement", idevenement);
    if (query.exec() && query.next()) {

        // id existe déjà
        return true;
    }
    // id n'existe pas encore
    return false;
}
bool evenements::verifiernom(QString nomevenement) {
    QSqlQuery query;
    query.prepare("SELECT nomevenement FROM evenements WHERE nomevenement = :nomevenement");
    query.bindValue(":nomevenement", nomevenement);
    if (query.exec() && query.next()) {

        // nom existe déjà
        return true;
    }
    // nom n'existe pas encore
    return false;
}



/*QSqlQueryModel* evenements::rechercher_nom(QString nomevenement)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    QSqlQuery query;
    if(nomevenement.isEmpty())
             QMessageBox::warning(0, "Erreur", "Le champ est vide!");
    if (!verifiernom(nomevenement)) {
           QMessageBox::warning(0, "Erreur", "Le nom  de levenement n'existe pas!");
           }

    query.prepare("SELECT * FROM evenements WHERE nomevenement LIKE :nomevenement ");
    query.bindValue(":nomevenement","%"+nomevenement+"%");
    query.exec();
    model->setQuery(query);
    return model;
}*/
QSqlQueryModel* evenements::tri_date()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenements ORDER BY datedebut DESC");
    return model;
}
QSqlQueryModel* evenements::rechercher_url(QString urlvideo)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    QSqlQuery query;


    query.prepare("SELECT * FROM evenements WHERE urlvideo LIKE :urlvideo ");
    query.bindValue(":urlvideo","%"+urlvideo+"%");
    query.exec();
    model->setQuery(query);
    return model;
}
QChartView *evenements::statistique()
{
    int stat=0;
    int Statii=0;


    QSqlQuery query;
    query.prepare("select * from evenements where etat LIKE '%termine%'");
    query.exec();
    while(query.next())
       stat++;

    query.prepare("select * from evenements where etat LIKE '%en cours%'");
    query.exec();
    while(query.next())
        Statii++;

     qDebug() <<stat << Statii  ;

     QPieSeries *series = new QPieSeries();
         series->append("termine",stat);
         series->append("en cours",Statii);

         // calculer le total des données
         int total = stat + Statii;

         // ajouter des étiquettes avec des pourcentages
         QString labeltermine = QString("termine (%1%)").arg((double)stat/total * 100, 0, 'f', 1);
         QString labelencours = QString("en cours (%1%)").arg((double)Statii/total * 100, 0, 'f', 1);
         series->slices().at(0)->setLabel(labeltermine);
         series->slices().at(1)->setLabel(labelencours);

         QPieSlice *slice = series->slices().at(0);
         slice->setExploded(true);
         slice->setColor("#00cc66");
         QPieSlice *slice2 = series->slices().at(1);
         slice2->setColor("#cc3300");
         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("statistique etat");

         series->setLabelsVisible();

         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->chart()->setAnimationOptions(QChart::AllAnimations);
         chartView->chart()->legend()->hide();
         return chartView;
}
