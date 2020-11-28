/*
Author: Adam Miller
Description: Header for WeatherWindow, the window that displays information about the weather
Date: 2020-11-11
*/

#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QWidget>
#include "WeatherCategory.h"
#include "mainwindow.h"
namespace Ui {
class WeatherWindow;
}

class WeatherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWindow(MainWindow * window, QWidget *parent = nullptr);
    ~WeatherWindow();

private:
    Ui::WeatherWindow *ui;          /*!<a qt-created pointer that represents the window itself*/
    WeatherCategory category;       /*!<the weather category (singleton) that is being used*/
    WeatherRecord *r ;              /*!<the weather record that is currently being used*/
    MainWindow * parentWindow;      /*!<the window that created this window*/
    int dayCounter;                 /*!<a counter that indicates which day in the day array we are currently dealing with*/
    int cORf;                       /*!<indicates whether the current temperature is celcius or farenheit; 0 = farenheit, 1 = celcius*/
    int cityIndex;                  /*!<indicates which city is currently being displayed*/
    void updateDisplay();
private slots:
    void on_searchBar_returnPressed();
    void on_BackButton_clicked();
    void on_celcButton_clicked();
    void on_farenButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_citiesBox_currentIndexChanged(int index);
};

#endif // WEATHERWINDOW_H
