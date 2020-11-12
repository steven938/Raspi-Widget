#include "newswindow.h"
#include "ui_newswindow.h"

NewsWindow::NewsWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

}

NewsWindow::~NewsWindow()
{
    delete ui;
}

void NewsWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    parentWindow->show();
    close();

}
