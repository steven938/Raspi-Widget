
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
 * \brief The MainWindow class is the primary window of the application.
 *
 * The MainWindow is the priamry window the application, and provides the user the ability to access StockWindow, WeatherWindow, and NewsWindow
 *
 * @author Adam Miller
 * @date 2020-11-29
 */
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
    Ui::MainWindow *ui;                     /*!<a qt object that represents the window itself*/
};
#endif // MAINWINDOW_H
