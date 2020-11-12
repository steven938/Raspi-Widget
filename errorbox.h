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
    explicit ErrorBox(QWidget *parent = nullptr);
    ~ErrorBox();
    void error(std::string message);

private:
    Ui::ErrorBox *ui;
};

#endif // ERRORBOX_H
