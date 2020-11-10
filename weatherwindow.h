#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QWidget>
#include "WeatherCategory.h"
#include <vector>
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
    std::vector<WeatherRecord> records;

private slots:
    void on_searchBar_returnPressed();
    void on_BackButton_clicked();
};

#endif // WEATHERWINDOW_H
