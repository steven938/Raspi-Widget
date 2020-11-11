#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QWidget>
#include "WeatherCategory.h"
namespace Ui {
class WeatherWindow;
}

class WeatherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWindow(QWidget *parent = nullptr);
    ~WeatherWindow();

private:
    Ui::WeatherWindow *ui;
    WeatherCategory category;
    WeatherRecord *r ;
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
