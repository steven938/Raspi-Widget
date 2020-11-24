/*
Author: Dhyey Patel
Description: CPP for stockWindow, the window that displays information about the stocks
Date: 2020-11-11
*/
#include "stockwindow.h"
#include "ui_stockwindow.h"
#include <iostream>

using namespace std;

/*
Name: stockWindow
Description: This is a constructor to create an instance of the stockWindow class
Parameter Descriptions: It needs a reference to the main window, and needs to get its widgets
Return Description: N/A
*/
stockWindow::stockWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stockWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

    vector<StockRecord> records;
    records.push_back(StockRecord("AAPL"));
    displayChart(records);

}

/*
Name: ~stockWindow
Description: This is a deconstructor to destroy the instance of the stockWindow class
Parameter Descriptions: N/A
Return Description: N/A
*/
stockWindow::~stockWindow()
{
    // Delete the ui created in the constructor
    delete ui;
}


/*
Name: on_BackButton_clicked
Description: Method will execute when the back button is clicked
Parameter Descriptions: N/A
Return Description: N/A
*/
void stockWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    QFont font = QFont("FreeSans",10,1);
    parentWindow->setFont(font);

    parentWindow->show();
    close();
}

/*
Name: on_BackButton_clicked
Description: Internal method that will display a stock chart given a vector of stock records (NEED TO FINISH IMPLEMENTATION, JUST CREATED AS PART OF THE SPIKE API TO LEARN ABOUT CHARTS IN QT)
Parameter Descriptions: vector of stock records that will be displayed 
Return Description: N/A, displays the chart 
*/
void stockWindow::displayChart(vector<StockRecord> toDisplay){

    // Create a line series variable series
    QLineSeries *series = new QLineSeries();
    
    // add the data from toDisplay into the line series
    for (int i = 4; i >= 0; i --){
        //cerr << i << " " << toDisplay[0].getClose((toDisplay.size() - i)) << endl;
        series->append(i,toDisplay[0].getClose((5 - i)));
    }

    // Create a chart, and add the series to the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Set the title for the chart
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

    // Create a legend for the chart
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Create a chartview to display the chart, and dispay the chart in the correct location
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);

}
