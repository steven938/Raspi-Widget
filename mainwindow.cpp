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

/*!
 * \brief MainWindow::MainWindow constructor
 *
 * Creates a MainWindow, and (somewhat humourously) chooses a random title for the window
 * \param parent required by qt, always a nullptr
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int choice = rand()%3;                      //chooses a random title for the window
    switch(choice){
    case 0:
        setWindowTitle("Habari: Your source for Stocks, Weather, and News");
        break;
    case 1:
        setWindowTitle("Habari: Not your grandpa's Bloomberg Terminal");
        break;
    case 2:
        setWindowTitle("Habari: Better than Google!");
        break;
    }
}
\
/*!
 * \brief MainWindow::~MainWindow a destructor
 * Deallocates dynamically allocated memory
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::on_stockButton_clicked Opens a StockWindow
 *
 * Called when the user clicks the stock button. Opens a StockWindow
 */
void MainWindow::on_stockButton_clicked(){
    stockWindow * w = new stockWindow(this,nullptr);        //initializes the stock window
    QFont font = QFont("FreeSans",10,1);                    //embeds the font into the window
    w->setFont(font);
    w->show();
}

/*!
 * \brief MainWindow::on_weatherButton_clicked Opens a WeatherWindow
 *
 * Called when the user clicks the weather button. Opens a WeatherWindow
 */
void MainWindow::on_weatherButton_clicked(){
    WeatherWindow* w = new WeatherWindow(this,nullptr); //initializes the weather window
    QFont font = QFont("FreeSans",10,1);                 //embeds the font into the window
    w->setFont(font);
    w->show();


}

/*!
 * \brief MainWindow::on_newsButton_clicked Opens a NewsWindow
 *
 * Called when the user clicks the news button. Opens a NewsWindow
 */
void MainWindow::on_newsButton_clicked(){
    NewsWindow* w = new NewsWindow(this,nullptr);       //initializes the newswindow
    QFont font = QFont("FreeSans",10,1);                //embeds the font into the window
    w->setFont(font);
    w->show();
}

