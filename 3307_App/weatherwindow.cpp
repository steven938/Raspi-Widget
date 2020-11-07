#include "weatherwindow.h"
#include "ui_weatherwindow.h"

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
