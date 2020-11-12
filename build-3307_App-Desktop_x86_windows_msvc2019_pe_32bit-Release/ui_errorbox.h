/********************************************************************************
** Form generated from reading UI file 'errorbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORBOX_H
#define UI_ERRORBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ErrorBox
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *errorMessage;

    void setupUi(QDialog *ErrorBox)
    {
        if (ErrorBox->objectName().isEmpty())
            ErrorBox->setObjectName(QString::fromUtf8("ErrorBox"));
        ErrorBox->resize(466, 340);
        buttonBox = new QDialogButtonBox(ErrorBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        errorMessage = new QLabel(ErrorBox);
        errorMessage->setObjectName(QString::fromUtf8("errorMessage"));
        errorMessage->setGeometry(QRect(40, 90, 371, 171));

        retranslateUi(ErrorBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), ErrorBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ErrorBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(ErrorBox);
    } // setupUi

    void retranslateUi(QDialog *ErrorBox)
    {
        ErrorBox->setWindowTitle(QCoreApplication::translate("ErrorBox", "Dialog", nullptr));
        errorMessage->setText(QCoreApplication::translate("ErrorBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorBox: public Ui_ErrorBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORBOX_H
