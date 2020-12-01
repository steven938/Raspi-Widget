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
    chartView->setMinimumHeight(ui->chartFrame->height());
    chartView->setMinimumWidth(ui->chartFrame->width());
    QFont font = QFont("FreeSans",10,1);
    chartView->setFont(font);
    chartView->setParent(ui->chartFrame);
}

StockChart::~StockChart()
{
    delete ui;
}

