/********************************************************************************
** Form generated from reading UI file 'newswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSWINDOW_H
#define UI_NEWSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewsWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *BackButton;

    void setupUi(QWidget *NewsWindow)
    {
        if (NewsWindow->objectName().isEmpty())
            NewsWindow->setObjectName(QString::fromUtf8("NewsWindow"));
        NewsWindow->resize(400, 300);
        horizontalLayout = new QHBoxLayout(NewsWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BackButton = new QPushButton(NewsWindow);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));

        horizontalLayout->addWidget(BackButton);


        retranslateUi(NewsWindow);

        QMetaObject::connectSlotsByName(NewsWindow);
    } // setupUi

    void retranslateUi(QWidget *NewsWindow)
    {
        NewsWindow->setWindowTitle(QCoreApplication::translate("NewsWindow", "Form", nullptr));
        BackButton->setText(QCoreApplication::translate("NewsWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewsWindow: public Ui_NewsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSWINDOW_H
