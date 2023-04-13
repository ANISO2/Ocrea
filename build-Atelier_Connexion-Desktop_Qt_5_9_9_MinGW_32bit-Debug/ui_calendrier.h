/********************************************************************************
** Form generated from reading UI file 'calendrier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDRIER_H
#define UI_CALENDRIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calendrier
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_rech;
    QDateTimeEdit *dateTimeEdit_fin;
    QDateTimeEdit *dateTimeEdit_deb;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_pic;

    void setupUi(QDialog *calendrier)
    {
        if (calendrier->objectName().isEmpty())
            calendrier->setObjectName(QStringLiteral("calendrier"));
        calendrier->resize(1124, 689);
        calendarWidget = new QCalendarWidget(calendrier);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(420, 170, 671, 391));
        calendarWidget->setStyleSheet(QLatin1String("background-color: rgb(184, 247, 213);\n"
"font: 75 10pt \"MS Shell Dlg 2\";\n"
""));
        pushButton = new QPushButton(calendrier);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(990, 617, 93, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}"));
        pushButton_2 = new QPushButton(calendrier);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 460, 111, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}"));
        label = new QLabel(calendrier);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 220, 101, 20));
        label->setStyleSheet(QStringLiteral("font: 12pt \"Dubai\";"));
        label_2 = new QLabel(calendrier);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(45, 330, 91, 21));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"Dubai\";"));
        label_3 = new QLabel(calendrier);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 270, 101, 21));
        label_3->setStyleSheet(QStringLiteral("font: 12pt \"Dubai\";"));
        lineEdit_rech = new QLineEdit(calendrier);
        lineEdit_rech->setObjectName(QStringLiteral("lineEdit_rech"));
        lineEdit_rech->setGeometry(QRect(160, 220, 113, 22));
        lineEdit_rech->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        dateTimeEdit_fin = new QDateTimeEdit(calendrier);
        dateTimeEdit_fin->setObjectName(QStringLiteral("dateTimeEdit_fin"));
        dateTimeEdit_fin->setGeometry(QRect(160, 330, 194, 22));
        dateTimeEdit_fin->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        dateTimeEdit_deb = new QDateTimeEdit(calendrier);
        dateTimeEdit_deb->setObjectName(QStringLiteral("dateTimeEdit_deb"));
        dateTimeEdit_deb->setGeometry(QRect(160, 270, 194, 22));
        dateTimeEdit_deb->setStyleSheet(QStringLiteral("background-color: rgb(184, 247, 213);"));
        label_4 = new QLabel(calendrier);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 80, 571, 41));
        label_4->setStyleSheet(QStringLiteral("font: 20pt \"Dubai\";"));
        label_5 = new QLabel(calendrier);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 570, 331, 20));
        label_5->setStyleSheet(QStringLiteral("font: 12pt \"Dubai\";"));
        label_pic = new QLabel(calendrier);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(980, 30, 81, 71));

        retranslateUi(calendrier);

        QMetaObject::connectSlotsByName(calendrier);
    } // setupUi

    void retranslateUi(QDialog *calendrier)
    {
        calendrier->setWindowTitle(QApplication::translate("calendrier", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("calendrier", "return", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("calendrier", "consulter", Q_NULLPTR));
        label->setText(QApplication::translate("calendrier", "id batterie", Q_NULLPTR));
        label_2->setText(QApplication::translate("calendrier", "date fin", Q_NULLPTR));
        label_3->setText(QApplication::translate("calendrier", "date debut", Q_NULLPTR));
        label_4->setText(QApplication::translate("calendrier", "calendrier charge des batteries", Q_NULLPTR));
        label_5->setText(QApplication::translate("calendrier", "le duree de chaque batterie est  30 jours", Q_NULLPTR));
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calendrier: public Ui_calendrier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDRIER_H
