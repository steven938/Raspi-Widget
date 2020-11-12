#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include "StockCategory.h"
#include "Record.h"
#include "mainwindow.h"



namespace Ui {
class stockWindow;
}

class stockWindow : public QWidget
{
    Q_OBJECT

public:
    explicit stockWindow(MainWindow * window, QWidget *parent = nullptr);
    ~stockWindow();
private slots:
    void on_BackButton_clicked();


private:
    Ui::stockWindow *ui;
    MainWindow * parentWindow;
    void displayChart(std::vector<StockRecord>);
};

#endif // STOCKWINDOW_H
