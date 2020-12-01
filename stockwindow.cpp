/*
Author: Dhyey Patel
Description: CPP for stockWindow, the window that displays information about the stocks
Date: 2020-11-11
*/

#include <iostream>


#include "stockwindow.h"
#include "ui_stockwindow.h"
#include "stockchart.h"
#include "errorbox.h"


using namespace std;

/*!
 * \brief stockWindow::stockWindow
 *
 * Initializes the stock window
 * Disables all the buttons to prevent user from being able to perform data operations prior to API Calls
 * Sets Buttons to a default value
 *
 * \param Window: Link back to the main window so that the back button can access it
 * \param parent: always nullptr it is required by QT
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
    ui->viewChart->setEnabled(false);

    //Initalize all the member variables to 0
    stockIndex = 0;
    chartPrice = 0;
    chartTime = 0;
    sortOption = 0;
    sortOrder = 0;

    vector<StockRecord> records;
    records.push_back(StockRecord("AAPL"));
    //updateChart(records);

}

/*!
 * \brief stockWindow::~stockWindow
 *
 * Deallocates dynamically allocated memory, destroying the object
 */
stockWindow::~stockWindow()
{
    delete ui;
    delete parentWindow;
    delete r;
}


/*!
 * \brief stockWindow::updateDisplay
 *
 * Based on the changes made to the options (sortOrder, sortOption) it will redo the sort
 * Based on the stock clicked it will update the Financial Metrics of that stock
 */
void stockWindow::updateDisplay(){

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

/*!
 * \brief stockWindow::updateChart
 *
 * Based on the stock options clicked (chartTime, chartPrice), it will update chartView, which then will be passed to stockchart to be displayed
 *
 * \param toDisplay: the stock record to display
 */
void stockWindow::updateChart(StockRecord toDisplay){
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

    // Create and set the X axis, which will be all the dates
    QCategoryAxis *axisX = new QCategoryAxis();
    QFont font = QFont("FreeSans",5,1);

    for (int i = displayDays - 1; i >= 0; i --){
        string date = toDisplay.getDate(i);
        QString qdate = QString::fromStdString(date);
        axisX->append(qdate,displayDays - i - 1);
    }

    axisX->setLabelsFont(font);

    chart->setAxisX(axisX, series);
                    //embeds the font into the window


    // Create a chartview to display the chart, and dispay the chart in the correct location
    if(chartView == NULL){
        delete chartView;
    }
    chartView = new QChartView(chart);
}

/*!
 * \brief stockWindow::on_BackButton_clicked
 *
 * When the back button is clicked close the current window and go back to the parent window
 */
void stockWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    QFont font = QFont("FreeSans",10,1);
    parentWindow->setFont(font);

    parentWindow->show();
    close();
}

/*!
 * \brief stockWindow::on_searchBar_returnPressed
 *
 * When a user searches for the stock it will create a new stock record, and then add it to the stock category
 * After the first search is executed it will enable all the buttons so the user can play around with the data
 */
void stockWindow::on_searchBar_returnPressed()
{
    try{category.search(ui->searchBar->text().toStdString());   //calls the search function of the WeatherCategory to call the API
    r = new StockRecord(category.getRecords()[category.getRecords().size()-1]);          //Accesses the first weatherrecord in the category's records vector.
    updateChart(*r);
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
    ui->viewChart->setEnabled(true);

    ui->stocksList->addItem(ui->searchBar->text());
    stockIndex = category.getRecords().size()-1;    // sets the correct stock index, meaning that the dropdown displays the correct city
    ui->stocksList->setCurrentIndex(stockIndex);
    }
    catch(...){
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error(ui->searchBar->text().toStdString()+" is not a valid stock!");
        error->setAttribute(Qt::WA_DeleteOnClose,true);
        error->show();
    }
}



/*!
 * \brief stockWindow::on_openButton_clicked
 *
 * When the open option is clicked change chartPrice to 0 which represents daily open price
 */
void stockWindow::on_openButton_clicked()
{
    this->chartPrice = 0;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_highButton_clicked
 *
 * When the high option is clicked change chartPrice to 1 which represents the daily high price
 */
void stockWindow::on_highButton_clicked()
{
    this->chartPrice = 1;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_lowButton_clicked
 *
 * When the low option is clicked change chartPrice to 2 which represents the daily low price
 */
void stockWindow::on_lowButton_clicked()
{
    this->chartPrice = 2;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_closeButton_clicked
 *
 * When the close option is clicked change chartPrice to 2 which represents the daily close price
 */
void stockWindow::on_closeButton_clicked()
{
    this->chartPrice = 3;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_pastWeek_clicked
 *
 * When the Past Week option is clicked change chartTime to 0 which represents 1 week
 */
void stockWindow::on_pastWeek_clicked()
{
    this->chartTime = 0;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_pastMonth_clicked
 *
 * When the Past Month option is clicked change chartTime to 1 which represents 1 month
 */
void stockWindow::on_pastMonth_clicked()
{
    this->chartTime = 1;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_pastMonth2_clicked
 *
 * When the Past 2 Months option is clicked change chartTime to 2 which represents 2 months
 */
void stockWindow::on_pastMonth2_clicked()
{
    this->chartTime = 2;
    // Update the chart based on the options
    updateChart(*r);

}

/*!
 * \brief stockWindow::on_pastMonth3_clicked
 *
 * When the Past 3 Months option is clicked change chartTime to 3 which represents 2 months
 */
void stockWindow::on_pastMonth3_clicked()
{
    this->chartTime = 3;
    // Update the chart based on the options
    updateChart(*r);
}

/*!
 * \brief stockWindow::on_alphaButton_clicked
 *
 * When the Alphabetic button is clicked change sortOption to 0, which represents sorting alphabetically
 */
void stockWindow::on_alphaButton_clicked()
{
    this->sortOption = 0;
    updateDisplay();
}

/*!
 * \brief stockWindow::on_mCapButton_clicked
 *
 * When the Market Capitilization button is clicked change sortOption to 1, which represents sorting by the market capitalization
 */
void stockWindow::on_mCapButton_clicked()
{
    this->sortOption = 1;
    updateDisplay();
}

/*!
 * \brief stockWindow::on_ascdButton_clicked
 *
 * When the Ascending button is clicked change sortOrder to 0, which represents sort in an ascending manner
 */
void stockWindow::on_ascdButton_clicked()
{
    this->sortOrder = 0;
    updateDisplay();
}

/*!
 * \brief stockWindow::on_descButton_clicked
 *
 * When the Descending button is clicked change sortOrder to 1, which represents sort in an descending manner
 */
void stockWindow::on_descButton_clicked()
{
    this->sortOrder = 1;
    updateDisplay();
}

/*!
 * \brief stockWindow::on_stocksList_currentIndexChanged
 *
 * When the company is changed using the drop down menu we need to change the data accordingly
 * They should have the same index as the records vector in category, so we can just set r to that record[index]
 *
 * \param index
 */
void stockWindow::on_stocksList_currentIndexChanged(int index)
{
    r = new StockRecord(category.getRecords()[index]);
    updateDisplay();
    updateChart(*r);

}

/*!
 * \brief stockWindow::on_viewChart_clicked
 *
 * When the View Stock Chart button is clicked create a stock window in which the stock chart will be displayed
 */
void stockWindow::on_viewChart_clicked()
{
    StockChart* w = new StockChart(nullptr, chartView); //initializes the weather window
    QFont font = QFont("FreeSans",10,1);                 //embeds the font into the window
    w->setFont(font);
    w->show();
}

/*!
 * \brief stockWindow::sortAlpha
 *
 * This function is passed as a parameter for the sort function
 * This function tells the sort function how to sort the data
 * In here it will search for the record that comes first alphabetically
 *
 * \param a: StockRecord that will be compared to b
 * \param b: StockRecord that will be compared to a
 * \return: returns true is StockRecord a comes before StockRecord b Alphabetically
 */
bool stockWindow::sortAlpha(StockRecord a,StockRecord b){
    if(a.getTicker().compare(b.getTicker()) <= 0){
        return true;
    }
    else{
        return false;
    }
}


/*!
 * \brief stockWindow::sortAlpha
 *
 * This function is passed as a parameter for the sort function
 * This function tells the sort function how to sort the data
 * In here it will search for the record that comes first based on the market capitalization
 *
 * \param a: StockRecord that will be compared to b
 * \param b: StockRecord that will be compared to a
 * \return: returns true is StockRecord a's market capitalization is smaller than StockRecord b's market capitalization
 */
bool stockWindow::sortMCap(StockRecord a,StockRecord b){
    return a.getMarketCap() < b.getMarketCap();
}





