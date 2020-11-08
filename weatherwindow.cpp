#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "WeatherCategory.h"
WeatherCategory category;
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
