#include "map.h"
#include "ui_map.h"
#include "evenements.h"
map::map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/search/charging+station+/@36.9016439,10.0990269,12z");
}

map::~map()
{
    delete ui;
}
