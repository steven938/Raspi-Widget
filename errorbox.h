#ifndef ERRORBOX_H
#define ERRORBOX_H

#include <QDialog>

namespace Ui {
class ErrorBox;
}

class ErrorBox : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorBox(QWidget *parent = nullptr); // Constructor
    ~ErrorBox(); // Destructor
    void error(std::string message); // Function to return a message to the user on the error that was thrown

private:
    Ui::ErrorBox *ui; // The user interface for error box to interact with
};

#endif // ERRORBOX_H
