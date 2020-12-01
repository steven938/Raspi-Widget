/*
Author: Dhyey Patel
Description: CPP for StockChart, the window that displays the stock chart
Date: 2020-11-11
*/

#include "stockchart.h"
#include "ui_stockchart.h"
/*!
 * \brief StockChart::StockChart displays a stock chart
 * \param parent required by qt, always a nullptr
 *
 * \author Dhyey Patel
 * \date 2020-11-30
 *
 */
StockChart::StockChart(QWidget *parent, QChartView *chartView) :
    QDialog(parent),
    ui(new Ui::StockChart)
{
    ui->setupUi(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chartFrame);
}

/*!
 * \brief stockWindow::~StockChart
 *
 * Deallocates dynamically allocated memory, destroying the object
 */
StockChart::~StockChart()
{
    delete ui;
}

