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
    Ui::StockChart *ui;
};

#endif // STOCKCHART_H
