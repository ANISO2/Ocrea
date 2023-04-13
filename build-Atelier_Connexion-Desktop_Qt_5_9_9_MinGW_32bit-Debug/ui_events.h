/********************************************************************************
** Form generated from reading UI file 'events.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTS_H
#define UI_EVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include "events.h"

QT_BEGIN_NAMESPACE

class Ui_events
{
public:
    events *calendarWidget;

    void setupUi(QDialog *events)
    {
        if (events->objectName().isEmpty())
            events->setObjectName(QStringLiteral("events"));
        events->resize(1082, 673);
        calendarWidget = new events(events);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(300, 100, 304, 218));

        retranslateUi(events);

        QMetaObject::connectSlotsByName(events);
    } // setupUi

    void retranslateUi(QDialog *events)
    {
        events->setWindowTitle(QApplication::translate("events", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class events: public Ui_events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTS_H
