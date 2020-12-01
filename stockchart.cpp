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
StockChart::StockChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockChart)
{
    ui->setupUi(this);
}

StockChart::~StockChart()
{
    delete ui;
}
