/*
Author: Dhyey Patel
Description: Header for stockWindow, the window that displays information about the stocks
Date: 2020-11-11
*/

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

// The public methods are just the constructor and deconstructors
public:
    explicit stockWindow(MainWindow * window, QWidget *parent = nullptr);
    ~stockWindow();

// Private slots are associated to buttons on the ui, and there is currently onle one button (more to come later)
private slots:
    void on_BackButton_clicked();

private:
    Ui::stockWindow *ui; 
    MainWindow * parentWindow;

    // Internal method called in the constructor to display the stock record
    void displayChart(std::vector<StockRecord>);
};

#endif // STOCKWINDOW_H
