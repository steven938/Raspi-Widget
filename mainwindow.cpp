/*
Author: Adam Miller
Description: CPP file that represents the main window of the application, where users can choose between stocks, weather, and news
Date: 2020-11-11
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "stockwindow.h"
#include "newswindow.h"
/*
Name: Constructor
Description: Creates a mainwindow
Parameter Descriptions: N/A
Return Description: N/A
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/*
Name: Destructor
Description: Deallocates dynamically allocated memories
Parameter Descriptions: N/A
Return Description: N/A
*/
MainWindow::~MainWindow()
{
    delete ui;
}
/*
Name: on_stockButton_clicked()
Description: Called when the user clicks the stock button. Opens a stock window
Parameter Descriptions: N/A
Return Description: N/A
*/
void MainWindow::on_stockButton_clicked(){
    stockWindow * w = new stockWindow(this,nullptr);        //initializes the stock window
    QFont font = QFont("FreeSans",10,1);
    w->setFont(font);
    w->show();
}
/*
Name: on_weatherButton_clicked()
Description: Called when the user clicks the weather button. Opens a weather window
Parameter Descriptions: N/A
Return Description: N/A
*/
void MainWindow::on_weatherButton_clicked(){
    WeatherWindow* w = new WeatherWindow(this,nullptr);
    QFont font = QFont("FreeSans",10,1);
    w->setFont(font);
    w->show();


}
/*
Name: on_newsButton_clicked()
Description: Called when the user clicks the news button. Opens a news window
Parameter Descriptions: N/A
Return Description: N/A
*/
void MainWindow::on_newsButton_clicked(){
    NewsWindow* w = new NewsWindow(this,nullptr);
    QFont font = QFont("FreeSans",10,1);
    w->setFont(font);
    w->show();
}

