/********************************************************************************
** Form generated from reading UI file 'smtp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMTP_H
#define UI_SMTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_smtp
{
public:

    void setupUi(QDialog *smtp)
    {
        if (smtp->objectName().isEmpty())
            smtp->setObjectName(QStringLiteral("smtp"));
        smtp->resize(834, 491);

        retranslateUi(smtp);

        QMetaObject::connectSlotsByName(smtp);
    } // setupUi

    void retranslateUi(QDialog *smtp)
    {
        smtp->setWindowTitle(QApplication::translate("smtp", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class smtp: public Ui_smtp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMTP_H
