#include "stockwindow.h"
#include "ui_stockwindow.h"


stockWindow::stockWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stockWindow)
{
    ui->setupUi(this);

    QLineSeries *series = new QLineSeries();



    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);

    QChart *chart = new QChart();
    //chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Line Chart Example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);

}

stockWindow::~stockWindow()
{
    delete ui;
}

void stockWindow::on_BackButton_clicked(){
    close();
}
