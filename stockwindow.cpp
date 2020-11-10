#include "stockwindow.h"
#include "ui_stockwindow.h"

stockWindow::stockWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stockWindow)
{
    ui->setupUi(this);
}

stockWindow::~stockWindow()
{
    delete ui;
}

void stockWindow::on_BackButton_clicked(){
    close();
}
