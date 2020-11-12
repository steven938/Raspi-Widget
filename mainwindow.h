/*
Author: Adam Miller
Description: Header file that represents the main window of the application, where users can choose between stocks, weather, and news
Date: 2020-11-11
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
   void on_stockButton_clicked();
   void on_weatherButton_clicked();
   void on_newsButton_clicked();

private:
    Ui::MainWindow *ui;                     //a qt object that represents the window itself
};
#endif // MAINWINDOW_H
