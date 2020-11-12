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

public:
    explicit NewsWindow(MainWindow * window, QWidget *parent = nullptr);
    ~NewsWindow();

private slots:
    void on_BackButton_clicked();

private:
    Ui::NewsWindow *ui;
    NewsCategory category;
    MainWindow * parentWindow;

};

#endif // NEWSWINDOW_H
