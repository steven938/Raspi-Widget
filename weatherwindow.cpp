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
/*
Name: constructor
Description: Initializes the weather window, and sets all buttons to disabled to prevent user from being able to perform data operations prior to API call
Parameter Descriptions: Window: pointer to the window that created this weather window; parent: a nullptr, required by qt;
Return Description:
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
    parentWindow = Window;                  //this sets up the pointer to the window that created this.
}
/*
Name: desctructor
Description: deallocates dynamically allocated memory, destroying the object
Parameter Descriptions:
Return Description:
*/
WeatherWindow::~WeatherWindow()
{
    //TO BE IMPLEMENTED - INCOMPLETE
    delete ui;
}
/*
Name: on_searchBar_returnPressed
Description: Called when the enter key is hit on the search bar. Sets up the window to display information for the location
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_searchBar_returnPressed(){
    category.search(ui->searchBar->text().toStdString());   //calls the search function of the WeatherCategory to call the API
    r = new WeatherRecord(category.getRecords()[0]);        //Accesses the first weatherrecord in the category's records vector.
                                                            //For the next stage, this will be implemented so that we can access any of
                                                            //the searches - currently, only the first search can be accessed
    updateDisplay();                                        //Updates the data on display
    //the next four lines enable the buttons that the user uses to interract with data
    ui->prevButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->celcButton->setEnabled(true);
    ui->farenButton->setEnabled((true));

}
/*
Name: on_BackButton_clicked()
Description: Called when the back buttin is clicked. Closes the window and returns to the main window
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::on_BackButton_clicked(){
    parentWindow->close();                      //these three lines create a new parent window, to ensure that in the case
                                                //that the parent window was closed while the weather window was open
                                                //we can return to a parent window
    parentWindow = new MainWindow();
    parentWindow->show();
    close();                                    //closes the weather window

}
/*
Name: updateDisplay()
Description:Updates the display to give the weather for the current day
Parameter Descriptions:
Return Description:
*/
void WeatherWindow::updateDisplay(){
    double temp;                                            //first, determines whether to display temperature in farenheit or celcius
    if (cORf == 0){
        temp = r->getDays()[dayCounter].getTempFaren();
    } else {
        temp = r->getDays()[dayCounter].getTempCelsius();
    }
    ui->temp->display(temp);
    //displays location, date, and description for current DailyWeather.
    ui->locationLabel->setText((ui->searchBar->text()));
    ui->dateLabel->setText(QString::fromStdString(r->getDays()[dayCounter].getDate().getStr()));
    ui->descLabel->setText(QString::fromStdString(r->getDays()[dayCounter].getDescription()));
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
    if(dayCounter == r->getDays().size()-1){   //error checking to prevent out-of-bounds error
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
