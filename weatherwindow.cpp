#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "WeatherCategory.h"

WeatherWindow::WeatherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);

}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}

void WeatherWindow::on_searchBar_returnPressed(){
    category.search(ui->searchBar->text().toStdString());
}
void WeatherWindow::on_BackButton_clicked(){
    close();

}

void WeatherWindow::on_torontoButton_clicked(){
    ui->temp->display(15);
    ui->humidity->display(10);
    ui->windSpeed->display(30);

}

void WeatherWindow::on_parisButton_clicked(){
    ui->temp->display(20);
    ui->humidity->display(35);
    ui->windSpeed->display(5);

}

void WeatherWindow::on_beijingButton_clicked(){
    ui->temp->display(13);
    ui->humidity->display(23);
    ui->windSpeed->display(10);

}
