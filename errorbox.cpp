#include "errorbox.h"
#include "ui_errorbox.h"

/*!
 * \brief ErrorBox::ErrorBox constructor
 *
 * creates an errorbox
 *
 * \param parent a nullptr, required by qt
 */
ErrorBox::ErrorBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorBox)
{
    ui->setupUi(this);
}


/*!
 * \brief ErrorBox::~ErrorBox destructor
 *
 * Destroys the object, deallocating memory
 */
ErrorBox::~ErrorBox()
{
    delete ui;
}

/*!
 * \brief ErrorBox::error displays an error message
 *
 * Displays an error message. Should be called BEFORE the show() method is called!
 *
 * \param MESSAGE const, A message to the user on the error that was thrown
 */
void ErrorBox::error(const std::string MESSAGE){
    ui->errorMessage->setText(QString::fromStdString((MESSAGE)));
}
