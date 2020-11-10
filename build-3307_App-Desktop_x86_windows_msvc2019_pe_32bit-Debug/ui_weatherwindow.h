/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QFormLayout *formLayout;
    QLineEdit *searchBar;
    QLabel *label;
    QPushButton *BackButton;

    void setupUi(QWidget *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName(QString::fromUtf8("WeatherWindow"));
        WeatherWindow->resize(400, 300);
        formLayout = new QFormLayout(WeatherWindow);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        searchBar = new QLineEdit(WeatherWindow);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        searchBar->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, searchBar);

        label = new QLabel(WeatherWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        BackButton = new QPushButton(WeatherWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, BackButton);


        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QWidget *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "Habari | Weather", nullptr));
        label->setText(QCoreApplication::translate("WeatherWindow", "What location's weather would you like to see?", nullptr));
        BackButton->setText(QCoreApplication::translate("WeatherWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
