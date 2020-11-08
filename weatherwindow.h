#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QWidget>

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
};

#endif // WEATHERWINDOW_H
