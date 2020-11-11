#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H

#include <QWidget>
#include "NewsCategory.h"

namespace Ui {
class NewsWindow;
}

class NewsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewsWindow(QWidget *parent = nullptr);
    ~NewsWindow();

private slots:
    void on_BackButton_clicked();


private:
    Ui::NewsWindow *ui;
    NewsCategory category;
};

#endif // NEWSWINDOW_H
