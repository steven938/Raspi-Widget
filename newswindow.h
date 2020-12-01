/*
Author: Dhyey Patel
Description: Header for newsWindow, the window that displays information about the news
Date: 2020-11-11
*/

#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H

#include <QWidget>
#include "NewsCategory.h"
#include "mainwindow.h"

namespace Ui {
class NewsWindow;
}
/*!
 * \brief The NewsWindow class displays and controls News data
 *
 * This class is the controller and view for the NewsCategory of data
 *
 * \author Dhyey Patel
 * \date 2020-11-11
 *
 */
class NewsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewsWindow(MainWindow * window, QWidget *parent = nullptr);
    ~NewsWindow();

private slots:
    void on_BackButton_clicked();
    void on_SearchByWordButton_clicked();
    void on_SearchByTopicButton_clicked();
    void clearResults();
    void displayArticles(std::vector<NewsRecord> records);

private:
    Ui::NewsWindow *ui;         /*!< a qt-created pointer that represents the window itself*/
    NewsCategory category;      /*!< the news category (singleton) that is being used*/
    MainWindow * parentWindow;  /*!< the window that created this window*/

};

#endif // NEWSWINDOW_H
