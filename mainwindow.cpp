#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherwindow.h"
#include "ui_weatherwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_stockButton_clicked(){
   // ui->stockButton->setVisible(false);

}

void MainWindow::on_weatherButton_clicked(){
    WeatherWindow* w = new WeatherWindow();
    QFont font = QFont("FreeSans",10,1);
    w->setFont(font);
    w->show();


}
void MainWindow::on_newsButton_clicked(){}

