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

private slots:
    void on_searchBar_returnPressed();
};

#endif // WEATHERWINDOW_H
