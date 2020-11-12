#include "stockwindow.h"
#include "ui_stockwindow.h"
#include <iostream>

using namespace std;

stockWindow::stockWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stockWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

    vector<StockRecord> records;
    records.push_back(StockRecord("APPL"));
    displayChart(records);

}

stockWindow::~stockWindow()
{
    delete ui;
}

void stockWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    parentWindow->show();
    close();
}

void stockWindow::displayChart(vector<StockRecord> toDisplay){

    QLineSeries *series = new QLineSeries();
    cerr << (toDisplay.size()) << endl;
    for (int i = static_cast<int>(5 - 1); i >= 0; i --){
        cerr << i << " " << toDisplay[0].getClose((toDisplay.size() - i)) << endl;
        series->append(i,toDisplay[0].getClose((toDisplay.size() - i)));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    string title = toDisplay[0].getCompanyName()+" 7-Day Stock Chart";
    QString qtitle = QString::fromStdString(title);
    chart->setTitle(qtitle);

    /*
    QCategoryAxis *axisX = new QCategoryAxis();
    for (int i = static_cast<int>(toDisplay.size()) - 1; i >= 0; i --){
        string date = toDisplay[0].getDate((toDisplay.size() - i));
        QString qdate = QString::fromStdString(date);
        axisX->append(qdate,i);
    }
    chart->setAxisX(axisX, series);*/

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);

}
