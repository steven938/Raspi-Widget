/*
Author: Adam Miller
Description: CPP for WeatherWindow, the window that displays information about the weather
Date: 2020-11-11
*/
#include <iostream>
#include <vector>
#include <QString>
#include <QMessageBox>


#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "WeatherCategory.h"
#include "errorbox.h"
#include "mainwindow.h"

using namespace std;

/*!
 * \brief WeatherWindow::WeatherWindow initializes the WeatherWindow
 *
 * Initializes the weather window, and sets all buttons to disabled to prevent user from being able to perform data operations prior to API call

 * \param Window pointer to the window that created this weather window
 * \param parent a nullptr, required by qt
 */
WeatherWindow::WeatherWindow(MainWindow *Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);                      //qt creates the ui for the window
    dayCounter = 0;                         //a counter that indicates which day in the day array we are currently dealing with
    cORf = 0;                               //indicates whether the current temperature is celcius or farenheit; 0 = farenheit, 1 = celcius
    //the next four lines disable buttons to prevent the user from operating on data that doesn't yet exist
    ui->prevButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->celcButton->setEnabled(false);
    ui->farenButton->setEnabled((false));
    ui->citiesBox->setEnabled(false);
    ui->dailyButton->setEnabled(false);
    ui->weekButton->setEnabled(false);
    ui->weatherByWeek->hide();


    weekOrDay = 0;
    parentWindow = Window;                  //this sets up the pointer to the window that created this.
}

/*!
 * \brief WeatherWindow::~WeatherWindow destorys the WeatherWindow
 *
 * Deallocates dynamically allocated memory, destroying the object
 */
WeatherWindow::~WeatherWindow()
{
    delete ui;
    delete parentWindow;
    delete r;
}
/*!
 * \brief WeatherWindow::on_searchBar_returnPressed Sets up the window to display information for a given location
 *
 * Called when the enter key is hit on the search bar. Uses the WeatherCategory search mechanism to receive a weather record from a search; enables buttons that were previously disabled, as there is now data for the user to interact with
 *
 */
void WeatherWindow::on_searchBar_returnPressed(){
    try{                                                        //incased in try/catch because category.search can throw an exception
        category.search(ui->searchBar->text().toStdString());   //calls the search function of the WeatherCategory to call the API
        delete r;
        r = new WeatherRecord(category.getRecords()[0]);        //Accesses the first weatherrecord in the category's records vector.
        updateDisplay();                                        //Updates the data on display
        //the next several lines enable the buttons that the user uses to interract with data
        ui->prevButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->celcButton->setEnabled(true);
        ui->farenButton->setEnabled((true));
        ui->citiesBox->setEnabled(true);
        ui->dailyButton->setEnabled(true);
        ui->weekButton->setEnabled(true);
        ui->citiesBox->addItem(ui->searchBar->text());
        cityIndex = category.getRecords().size()-1;
        ui->citiesBox->setCurrentIndex(cityIndex);
    }catch(...){                                                //in case the search string is an invalid city
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error(ui->searchBar->text().toStdString()+" is not a valid city!");
        error->setAttribute(Qt::WA_DeleteOnClose,true);
        error->show();
    }

}

/*!
 * \brief WeatherWindow::on_BackButton_clicked is called when the back button is clicked
 *
 * Called when the back buttin is clicked. Closes the window and returns to the main window
 */
void WeatherWindow::on_BackButton_clicked(){
    parentWindow->close();                      //these three lines create a new parent window, to ensure that in the case
    //that the parent window was closed while the weather window was open
    //we can return to a parent window

    parentWindow = new MainWindow();
    QFont font = QFont("FreeSans",10,1);
    parentWindow->setFont(font);
    parentWindow->show();
    close();                                    //closes the weather window

}
/*!
 * \brief WeatherWindow::updateDisplay Updates the display to give the weather for the current day
 *
 * Uses cORf and dayCounter to determine what the current DailyWeather is and what the correct unit of measurement is, then updates the display accordingly
 */
void WeatherWindow::updateDisplay(){
    double temp;                                            //first, determines whether to display temperature in farenheit or celcius
    if (cORf == 0){
        temp = r->getTempFahren(dayCounter);
    } else {
        temp = r->getTempCelsius(dayCounter);
    }
    if (weekOrDay == 0){
        ui->temp->display(temp);
        ui->locationLabel->setText(QString::fromStdString(r->getLocation()));
        cerr<<r->getLocation()<<endl;
        //displays location, date, and description for current DailyWeather.
        ui->dateLabel->setText(QString::fromStdString(r->getDate(dayCounter).getStr()));
        ui->descLabel->setText(QString::fromStdString(r->getDescription(dayCounter)));
    } else if (weekOrDay == 1){
        ui->desc_day1->setText(QString::fromStdString(r->getDescription(0)));
        ui->desc_day2->setText(QString::fromStdString(r->getDescription(1)));
        ui->desc_day3->setText(QString::fromStdString(r->getDescription(2)));
        ui->desc_day4->setText(QString::fromStdString(r->getDescription(3)));
        ui->desc_day5->setText(QString::fromStdString(r->getDescription(4)));
        //ui->dateLabel->setText(QString::fromStdString(r->getDate(0).getStr());
    }

}

/*!
 * \brief WeatherWindow::on_celcButton_clicked changes display to celcius
 *
 *  Called when the celcius radio button is clicked. Updates display so that data is in celcius; does this by updating CorF
*
 */
void WeatherWindow::on_celcButton_clicked()
{
    cORf = 1;
    updateDisplay();
}

/*!
 * \brief WeatherWindow::on_farenButton_clicked changes display to fahrenheit
 *
 * Called when the Fahrenheit radio button is clicked. Updates display so that data is in farenheit

 */
void WeatherWindow::on_farenButton_clicked()
{
    cORf = 0;
    updateDisplay();
}


/*!
 * \brief WeatherWindow::on_prevButton_clicked shows the previous day
 *
 * Called when the previous day button is clicked. Decrements dayCounter to show the previous day's data
 *
 */
void WeatherWindow::on_prevButton_clicked()
{
    if(dayCounter == 0){                        //error checking to prevent out-of-bounds error
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no previous day!");
        error->setAttribute(Qt::WA_DeleteOnClose,true);
        error->show();
        return;
    }
    dayCounter --;
    updateDisplay();
}

/*!
 * \brief WeatherWindow::on_nextButton_clicked shows the previous day
 *
 * Called when the next day button is clicked. Increments dayCounter to show the next day's data
 *
 */
/*!
 * \brief WeatherWindow::on_nextButton_clicked
 */
void WeatherWindow::on_nextButton_clicked()
{
    if(dayCounter == r->getNumDays()-1){   //error checking to prevent out-of-bounds error
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no next day!");
        error->setAttribute(Qt::WA_DeleteOnClose,true);
        error->show();
        return;
    }
    dayCounter++;
    updateDisplay() ;
}

/*!
 * \brief WeatherWindow::on_citiesBox_currentIndex Changed switches the city displayed
 *
 * This function is called when the user clicks on a city in the visual cities list. It updates r to be about the city just clicked, and calles WeatherWindow::updateDisplay() to update the display
 *
 * \param index the index number of the city that was clicked on. This corresponds to the index numbers in the records vector of the WeatherCategory class.
 */
void WeatherWindow::on_citiesBox_currentIndexChanged(const int INDEX)
{
    *r = category.getRecords()[INDEX];
    updateDisplay();
}



void WeatherWindow::on_weekButton_clicked()
{
    ui->weatherByDay->hide();
    ui->weatherByWeek->show();
    weekOrDay = 1;
    updateDisplay();



}

void WeatherWindow::on_dailyButton_clicked()
{
    weekOrDay = 0;
    ui->weatherByDay->show();
    ui->weatherByWeek->hide();
    updateDisplay();
}

