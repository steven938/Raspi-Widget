/*
Author: Dhyey Patel
Description: Header file that defines a StockChart. This is the UI that will display the stock chart
Date: 2020-11-04
*/
#ifndef STOCKCHART_H
#define STOCKCHART_H

#include <QDialog>
#include <QtCharts>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

namespace Ui {
class StockChart;
}

class StockChart : public QDialog
{
    Q_OBJECT

public:
    explicit StockChart(QWidget *parent = nullptr, QChartView * chartView = nullptr);
    ~StockChart();

private:
    Ui::StockChart *ui;     /*!< a qt-created pointer that represents the window itself*/
};

#endif // STOCKCHART_H
