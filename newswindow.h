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


private:
    Ui::NewsWindow *ui;
    NewsCategory category;
    MainWindow * parentWindow;

};

#endif // NEWSWINDOW_H
