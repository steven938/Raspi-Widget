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

    //the next four lines disable buttons to prevent the user from operating on data that doesn't yet exist
    ui->stocksList->setEnabled(false);
    ui->openButton->setEnabled(false);
    ui->closeButton->setEnabled(false);
    ui->highButton->setEnabled((false));
    ui->lowButton->setEnabled(false);
    ui->alphaButton->setEnabled(false);
    ui->mCapButton->setEnabled(false);
    ui->ascdButton->setEnabled(false);
    ui->descButton->setEnabled(false);
    ui->pastWeek->setEnabled(false);
    ui->pastMonth->setEnabled(false);
    ui->pastMonth2->setEnabled(false);
    ui->pastMonth3->setEnabled(false);
    ui->sortStocks->hide();
    ui->compInfo->hide();
    ui->chartFrameBox->hide();
    ui->chartOptions->hide();
    ui->listOptions->hide();

    //Initalize all the parameters to 0
    stockIndex = 0;
    chartPrice = 0;
    chartTime = 0;
    sortOption = 0;
    sortOrder = 0;





    vector<StockRecord> records;
    records.push_back(StockRecord("AAPL"));
    //displayChart(records);

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


void stockWindow::updateDisplay(){

    // Update the chart based on the options
    displayChart(*r);


    // Update the company information section

    ui->compName->setText(QString::fromStdString(r->getCompanyName()));
    ui->mCap->setText(QString::fromStdString(to_string(((long long)r->getMarketCap()))));
    ui->ebitShare->setText(QString::fromStdString(to_string(r->getEBITShare())));
    ui->currentRatio->setText(QString::fromStdString(to_string(r->getCurrentRatio())));
    ui->payoutRatio->setText(QString::fromStdString(to_string(r->getPayoutRatio())));
    ui->grossMargin->setText(QString::fromStdString(to_string(r->getGrossMargin())));


    // Update the sort stocks section

    // Sort the stocks, dont change the order in the StockCategory, so use another variable
    sorted = category.getRecords();
    if(this->sortOption == 0){
        sort(sorted.begin(),sorted.end(),sortAlpha);
    }
    else if (this->sortOption == 1){
        sort(sorted.begin(),sorted.end(),sortMCap);
    }

    // If the sort order is descending then reverse the vector
    if(this->sortOrder == 1){
        reverse(sorted.begin(),sorted.end());
    }

    // Generate the output string
    string sortedOutput = "";
    for (int i = 0; i < static_cast<int>(sorted.size()); i++){
        if (i == 0){
            sortedOutput = sortedOutput + sorted[i].getTicker();
        }
        else{
            sortedOutput = sortedOutput + ", " +sorted[i].getTicker();
        }
    }
    // Print the string on the window
    ui->sortedStocks->setText(QString::fromStdString(sortedOutput));

}

/*
Name: on_BackButton_clicked
Description: Internal method that will display a stock chart given a vector of stock records (NEED TO FINISH IMPLEMENTATION, JUST CREATED AS PART OF THE SPIKE API TO LEARN ABOUT CHARTS IN QT)
Parameter Descriptions: vector of stock records that will be displayed 
Return Description: N/A, displays the chart 
*/
void stockWindow::displayChart(StockRecord toDisplay){
    qDebug() << "running display chart with...";
    qDebug() << chartTime;
    int displayDays = 0;
    if(this->chartTime == 0){
        displayDays = 7;
    }
    else if(this->chartTime == 1){
        displayDays = 30;
    }
    else if(this->chartTime == 2){
        displayDays = 60;
    }
    else if(this->chartTime == 3){
        displayDays = 90;
    }
    // Create a line series variable series
    QLineSeries *series = new QLineSeries();
    
    // add the data from toDisplay into the line series
    for (int i = displayDays; i >= 0; i --){
        //cerr << i << " " << toDisplay.getClose((displayDays - i)) << endl;
        if(this->chartPrice == 0){
            series->append(i,toDisplay.getOpen((displayDays+1 - i)));
        }
        else if(this->chartPrice == 1){
            series->append(i,toDisplay.getHigh((displayDays+1 - i)));
        }
        else if(this->chartPrice == 2){
            series->append(i,toDisplay.getLow((displayDays+1 - i)));
        }
        else if(this->chartPrice == 3){
            series->append(i,toDisplay.getClose((displayDays+1 - i)));
        }
    }

    // Create a chart, and add the series to the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Set the title for the chart
    string title = toDisplay.getCompanyName()+" Stock Chart";
    QString qtitle = QString::fromStdString(title);
    chart->setTitle(qtitle);


    QCategoryAxis *axisX = new QCategoryAxis();
    for (int i = displayDays - 1; i >= 0; i --){
        string date = toDisplay.getDate(i);
        QString qdate = QString::fromStdString(date);
        axisX->append(qdate,displayDays - i - 1);
    }
    chart->setAxisX(axisX, series);


    // Create a chartview to display the chart, and dispay the chart in the correct location
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chartFrame);
    chartView->repaint();

}

void stockWindow::on_searchBar_returnPressed()
{
    category.search(ui->searchBar->text().toStdString());   //calls the search function of the WeatherCategory to call the API
    r = new StockRecord(category.getRecords()[category.getRecords().size()-1]);          //Accesses the first weatherrecord in the category's records vector.
    displayChart(*r);
    updateDisplay();                                        //Updates the data on display

    // Enable all of the disabled buttons now that there is some data to work with
    ui->stocksList->setEnabled(true);
    ui->openButton->setEnabled(true);
    ui->closeButton->setEnabled(true);
    ui->highButton->setEnabled((true));
    ui->lowButton->setEnabled(true);
    ui->alphaButton->setEnabled(true);
    ui->mCapButton->setEnabled(true);
    ui->ascdButton->setEnabled(true);
    ui->descButton->setEnabled(true);
    ui->pastWeek->setEnabled(true);
    ui->pastMonth->setEnabled(true);
    ui->pastMonth2->setEnabled(true);
    ui->pastMonth3->setEnabled(true);

    ui->stocksList->addItem(ui->searchBar->text());
    stockIndex = category.getRecords().size()-1;    // sets the correct stock index, meaning that the dropdown displays the correct city
    ui->stocksList->setCurrentIndex(stockIndex);
}




void stockWindow::on_openButton_clicked()
{
    this->chartPrice = 0;
    updateDisplay();
}

void stockWindow::on_highButton_clicked()
{
    this->chartPrice = 1;
    updateDisplay();
}

void stockWindow::on_lowButton_clicked()
{
    this->chartPrice = 2;
    updateDisplay();
}

void stockWindow::on_closeButton_clicked()
{
    this->chartPrice = 3;
    updateDisplay();
}

void stockWindow::on_pastWeek_clicked()
{
    this->chartTime = 0;
    updateDisplay();
}

void stockWindow::on_pastMonth_clicked()
{
    this->chartTime = 1;
    updateDisplay();
}

void stockWindow::on_pastMonth2_clicked()
{
    this->chartTime = 2;
    updateDisplay();

}

void stockWindow::on_pastMonth3_clicked()
{
    this->chartTime = 3;
    updateDisplay();
}

void stockWindow::on_alphaButton_clicked()
{
    this->sortOption = 0;
    updateDisplay();
}

void stockWindow::on_mCapButton_clicked()
{
    this->sortOption = 1;
    updateDisplay();
}

void stockWindow::on_ascdButton_clicked()
{
    this->sortOrder = 0;
    updateDisplay();
}

void stockWindow::on_descButton_clicked()
{
    this->sortOrder = 1;
    updateDisplay();
}




void stockWindow::on_stockView_clicked()
{
    ui->sortStocks->hide();
    ui->compInfo->hide();
    ui->chartFrameBox->show();
    ui->chartOptions->show();
    ui->listOptions->hide();
}

void stockWindow::on_listView_clicked()
{
    ui->sortStocks->show();
    ui->compInfo->hide();
    ui->chartFrameBox->hide();
    ui->chartOptions->hide();
    ui->listOptions->show();
}

void stockWindow::on_companyView_clicked()
{
    ui->sortStocks->hide();
    ui->compInfo->show();
    ui->chartFrameBox->hide();
    ui->chartOptions->hide();
    ui->listOptions->hide();
}


bool stockWindow::sortAlpha(StockRecord a,StockRecord b){
    if(a.getTicker().compare(b.getTicker()) <= 0){
        return true;
    }
    else{
        return false;
    }
}

bool stockWindow::sortMCap(StockRecord a,StockRecord b){
    return a.getMarketCap() < b.getMarketCap();
}

void stockWindow::on_stocksList_currentIndexChanged(int index)
{
    r = new StockRecord(category.getRecords()[index]);
    updateDisplay();
}
