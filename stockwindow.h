#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QWidget>
#include "StockCategory.h"

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
};

#endif // STOCKWINDOW_H
