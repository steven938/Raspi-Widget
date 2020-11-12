#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QWidget>
#include "StockCategory.h"
#include "Record.h"

#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

namespace Ui {
class stockWindow;
}

class stockWindow : public QWidget
{
    Q_OBJECT

public:
    explicit stockWindow(QWidget *parent = nullptr);
    ~stockWindow();
private slots:
    void on_BackButton_clicked();


private:
    Ui::stockWindow *ui;
    void displayChart(std::vector<StockRecord>);
};

#endif // STOCKWINDOW_H
