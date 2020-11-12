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
    Ui::WeatherWindow *ui;
    WeatherCategory category;
    WeatherRecord *r ;
    MainWindow * parentWindow;
    DailyWeather *dw ;
    int dayCounter;
    int cORf;
    void updateDisplay();
private slots:
    void on_searchBar_returnPressed();
    void on_BackButton_clicked();
    void on_celcButton_clicked();
    void on_farenButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
};

#endif // WEATHERWINDOW_H
