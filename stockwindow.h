/*
Author: Dhyey Patel
Description: Header file that defines a stockWindow. This is the UI with which the user will interact
Date: 2020-11-04
*/

#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include "StockCategory.h"
#include "mainwindow.h"



namespace Ui {
class stockWindow;
}
/*!
 * \brief The stockWindow class displays information on stocks
 *
 * Controller and view for stock data -can display stock charts, search for stocks, and look up financial information
 *
 * @author Dhyey Patel
 * @date 2020-11-04
 *
 */
class stockWindow : public QWidget
{
    Q_OBJECT

public:
    explicit stockWindow(MainWindow * window, QWidget *parent = nullptr);
    ~stockWindow();

private slots:
    void on_BackButton_clicked();
    void on_searchBar_returnPressed();
    void on_openButton_clicked();
    void on_highButton_clicked();
    void on_lowButton_clicked();
    void on_closeButton_clicked();
    void on_pastWeek_clicked();
    void on_pastMonth_clicked();
    void on_alphaButton_clicked();
    void on_mCapButton_clicked();
    void on_ascdButton_clicked();
    void on_descButton_clicked();
    void on_pastMonth2_clicked();
    void on_pastMonth3_clicked();
    void on_stocksList_currentIndexChanged(int index);
    void on_viewChart_clicked();

private:
    Ui::stockWindow *ui;            /*!< a qt-created pointer that represents the window itself*/
    MainWindow * parentWindow;      /*!< the window that created this window*/
    StockCategory category;         /*!< the stock category (singleton) that is being used*/
    std::vector<StockRecord> sorted;/*!< the sorted records vector*/
    StockRecord *r ;                /*!< the stock record that is currently being used*/
    int stockIndex;                 /*!< indicates which stock is currently being displayed*/
    int chartPrice;                 /*!< indicates what the price displayed on the chart should be; 0 = open, 1 = high, 2 = low, 3 = close*/
    int chartTime;                  /*!< indicates what the timeline for the chart should be; 0 = past week, 1 = past month, 2 = past 2 months, 3 = past 3 months*/
    int sortOption;                 /*!< indicates what the stocks need to sorted by; 0 = Alphabetical (ticker), 1 = Market Capitalization*/
    int sortOrder;                  /*!< indicates what the order of the sort type should be, 0 = Ascending, 1 = Descending*/
    QChartView *chartView;          /*!< indicates the chart that needs to be created*/


    // Private Display functions
    void updateChart(StockRecord);
    void updateDisplay();

    // Private sorting functions
    static bool sortAlpha(StockRecord,StockRecord);
    static bool sortMCap(StockRecord,StockRecord);
};

#endif // STOCKWINDOW_H
