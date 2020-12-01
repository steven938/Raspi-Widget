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

class NewsWindow : public QWidget
{
    Q_OBJECT

// The public methods are just the constructor and deconstructors
public:
    explicit NewsWindow(MainWindow * window, QWidget *parent = nullptr);
    ~NewsWindow();

// Private slots are associated to buttons on the ui, and there is currently onle one button (more to come later)
private slots:
    void on_BackButton_clicked();
    void on_SearchByWordButton_clicked();
    void on_SearchByTopicButton_clicked();
    void clearResults();
    void displayArticles(std::vector<NewsRecord> records, NewsCategory *newsCategory);

private:
    Ui::NewsWindow *ui;         /*!< a qt-created pointer that represents the window itself*/
    NewsCategory category;      /*!< the news category (singleton) that is being used*/
    MainWindow * parentWindow;  /*!< the window that created this window*/

};

#endif // NEWSWINDOW_H
