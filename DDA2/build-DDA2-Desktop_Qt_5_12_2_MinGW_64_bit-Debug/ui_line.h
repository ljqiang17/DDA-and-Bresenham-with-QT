/********************************************************************************
** Form generated from reading UI file 'line.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_H
#define UI_LINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Line
{
public:

    void setupUi(QWidget *Line)
    {
        if (Line->objectName().isEmpty())
            Line->setObjectName(QString::fromUtf8("Line"));
        Line->resize(400, 300);

        retranslateUi(Line);

        QMetaObject::connectSlotsByName(Line);
    } // setupUi

    void retranslateUi(QWidget *Line)
    {
        Line->setWindowTitle(QApplication::translate("Line", "Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Line: public Ui_Line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_H
