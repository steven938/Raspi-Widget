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
    QLabel *dateLabel;
    QLabel *DescLabel;
    QLabel *label;
    QLineEdit *searchBar;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLabel *TempLabel;
    QPushButton *BackButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *locationLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName(QString::fromUtf8("WeatherWindow"));
        WeatherWindow->resize(590, 466);
        horizontalLayoutWidget = new QWidget(WeatherWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 16, 16));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout(WeatherWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dateLabel = new QLabel(WeatherWindow);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        gridLayout_2->addWidget(dateLabel, 3, 2, 1, 1);

        DescLabel = new QLabel(WeatherWindow);
        DescLabel->setObjectName(QString::fromUtf8("DescLabel"));

        gridLayout_2->addWidget(DescLabel, 5, 2, 1, 1);

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

        label_4 = new QLabel(WeatherWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 5, 3, 1, 1);

        TempLabel = new QLabel(WeatherWindow);
        TempLabel->setObjectName(QString::fromUtf8("TempLabel"));

        gridLayout_2->addWidget(TempLabel, 6, 2, 1, 1);

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

        pushButton_2 = new QPushButton(WeatherWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 7, 2, 1, 1);

        label_2 = new QLabel(WeatherWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 1);

        label_3 = new QLabel(WeatherWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 1, 1, 1);

        label_5 = new QLabel(WeatherWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 6, 1, 1, 1);

        pushButton = new QPushButton(WeatherWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 7, 1, 1, 1);

        locationLabel = new QLabel(WeatherWindow);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout_2->addWidget(locationLabel, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);


        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QWidget *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "Habari | Weather", nullptr));
        dateLabel->setText(QCoreApplication::translate("WeatherWindow", "TextLabel", nullptr));
        DescLabel->setText(QCoreApplication::translate("WeatherWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("WeatherWindow", "What location's weather would you like to see?", nullptr));
        label_4->setText(QCoreApplication::translate("WeatherWindow", "Description:", nullptr));
        TempLabel->setText(QCoreApplication::translate("WeatherWindow", "TextLabel", nullptr));
        BackButton->setText(QCoreApplication::translate("WeatherWindow", "Back", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WeatherWindow", "Temperature Selection", nullptr));
        radioButton->setText(QCoreApplication::translate("WeatherWindow", "Celcius", nullptr));
        radioButton_2->setText(QCoreApplication::translate("WeatherWindow", "Farenheit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WeatherWindow", "Next Day", nullptr));
        label_2->setText(QCoreApplication::translate("WeatherWindow", "Location:", nullptr));
        label_3->setText(QCoreApplication::translate("WeatherWindow", "Date:", nullptr));
        label_5->setText(QCoreApplication::translate("WeatherWindow", "Temperature", nullptr));
        pushButton->setText(QCoreApplication::translate("WeatherWindow", "Previous Day", nullptr));
        locationLabel->setText(QCoreApplication::translate("WeatherWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
