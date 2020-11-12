#include "errorbox.h"
#include "ui_errorbox.h"

/*
Name: Constructor
Description: Constructs a ErrorBox object
Parameter Descriptions: day: parent is always a null pointer
Return Description: N/A
*/
ErrorBox::ErrorBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorBox)
{
    ui->setupUi(this);
}

/*
Name: Destructor
Description: Destroys the object, deallocating memory
Parameter Descriptions: N/A
Return Description: N/A
*/
ErrorBox::~ErrorBox()
{
    delete ui;
}

/*
Name: error
Description: Return error message for the associated error
Parameter Descriptions: message which is the string to be returned
Return Description: A message to the user on the error that was thrown
*/
void ErrorBox::error(std::string message){
    ui->errorMessage->setText(QString::fromStdString((message)));
}
