#include "newswindow.h"
#include "ui_newswindow.h"

NewsWindow::NewsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
}

NewsWindow::~NewsWindow()
{
    delete ui;
}
