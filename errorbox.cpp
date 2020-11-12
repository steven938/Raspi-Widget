#include "errorbox.h"
#include "ui_errorbox.h"

ErrorBox::ErrorBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorBox)
{
    ui->setupUi(this);
}

ErrorBox::~ErrorBox()
{
    delete ui;
}

void ErrorBox::error(std::string message){
    ui->errorMessage->setText(QString::fromStdString((message)));
}
