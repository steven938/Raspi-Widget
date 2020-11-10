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
