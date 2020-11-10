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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *searchBar;
    QPushButton *BackButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName(QString::fromUtf8("WeatherWindow"));
        WeatherWindow->resize(400, 300);
        horizontalLayoutWidget = new QWidget(WeatherWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 16, 16));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout(WeatherWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(WeatherWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        searchBar = new QLineEdit(WeatherWindow);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font);

        gridLayout_2->addWidget(searchBar, 1, 1, 1, 1);

        BackButton = new QPushButton(WeatherWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        gridLayout_2->addWidget(BackButton, 0, 0, 1, 1);

        groupBox = new QGroupBox(WeatherWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QWidget *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "Habari | Weather", nullptr));
        label->setText(QCoreApplication::translate("WeatherWindow", "What location's weather would you like to see?", nullptr));
        BackButton->setText(QCoreApplication::translate("WeatherWindow", "Back", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WeatherWindow", "Temperature Selection", nullptr));
        radioButton->setText(QCoreApplication::translate("WeatherWindow", "Celcius", nullptr));
        radioButton_2->setText(QCoreApplication::translate("WeatherWindow", "Farenheit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
