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
    parentWindow = Window;                  //this sets up the pointer to the window that created this.
}

/*!
 * \brief WeatherWindow::~WeatherWindow destorys the WeatherWindow
 *
 * Deallocates dynamically allocated memory, destroying the object
 */
WeatherWindow::~WeatherWindow()
{
    //TO BE IMPLEMENTED - INCOMPLETE
    delete ui;
}
/*!
 * \brief WeatherWindow::on_searchBar_returnPressed Sets up the window to display information for a given location
 *
 * Called when the enter key is hit on the search bar. Uses the WeatherCategory search mechanism to receive a weather record from a search; enables buttons that were previously disabled, as there is now data for the user to interact with
 *
 */
void WeatherWindow::on_searchBar_returnPressed(){
   try{ category.search(ui->searchBar->text().toStdString());   //calls the search function of the WeatherCategory to call the API
    r = new WeatherRecord(category.getRecords()[0]);        //Accesses the first weatherrecord in the category's records vector.
                                                            //For the next stage, this will be implemented so that we can access any of
                                                            //the searches - currently, only the first search can be accessed
    updateDisplay();                                        //Updates the data on display
    //the next four lines enable the buttons that the user uses to interract with data
    ui->prevButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->celcButton->setEnabled(true);
    ui->farenButton->setEnabled((true));
    ui->citiesBox->setEnabled(true);
    ui->citiesBox->addItem(ui->searchBar->text());
    cityIndex = category.getRecords().size()-1;
    ui->citiesBox->setCurrentIndex(cityIndex);
     }catch(...){
        //cerr<<"didn't work"<<endl;
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error(ui->searchBar->text().toStdString()+" is not a valid city!");
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
/*
Name: updateDisplay()
Description:
Parameter Descriptions:
Return Description:
*/
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
    ui->temp->display(temp);
    ui->locationLabel->setText(QString::fromStdString(r->getLocation()));
    cerr<<r->getLocation()<<endl;
    //displays location, date, and description for current DailyWeather.
    ui->dateLabel->setText(QString::fromStdString(r->getDate(dayCounter).getStr()));
    ui->descLabel->setText(QString::fromStdString(r->getDescription(dayCounter)));
}

/*
Name: on_celcButton_clicked()
Description: Called when the celcius radio button is clicked. Updates display so that data is in celcius
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_celcButton_clicked()
{
    cORf = 1;
    updateDisplay();
}

/*
Name: on_farenButton_clicked()
Description: Called when the celcius radio button is clicked. Updates display so that data is in farenheit
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_farenButton_clicked()
{
    cORf = 0;
    updateDisplay();
}

/*
Name: on_prevButton_clicked()
Description: Called when the previous day button is clicked. Decrements dayCounter to show the previous day's data
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_prevButton_clicked()
{
    if(dayCounter == 0){                        //error checking to prevent out-of-bounds error
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no previous day!");
        error->show();
        return;
    }
    dayCounter --;
    updateDisplay();
}
/*
Name: on_nextButton_clicked()
Description: Called when the next day button is clicked. Increments dayCounter to show the next day's data
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_nextButton_clicked()
{
    if(dayCounter == r->getNumDays()-1){   //error checking to prevent out-of-bounds error
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no next day!");
        error->show();
        return;
    }
    dayCounter++;
    updateDisplay() ;
}

/*!
 * \brief WeatherWindow::on_citiesBox_currentIndexChanged switches the city displayed
 *
 * This function is called when the user clicks on a city in the visual cities list. It updates r to be about the city just clicked, and calles WeatherWindow::updateDisplay() to update the display
 *
 * \param index the index number of the city that was clicked on. This corresponds to the index numbers in the records vector of the WeatherCategory class.
 */
void WeatherWindow::on_citiesBox_currentIndexChanged(int index)
{
    *r = category.getRecords()[index];
    updateDisplay();
}
