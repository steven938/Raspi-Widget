#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H

#include <QWidget>

namespace Ui {
class NewsWindow;
}

class NewsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewsWindow(QWidget *parent = nullptr);
    ~NewsWindow();

private:
    Ui::NewsWindow *ui;
};

#endif // NEWSWINDOW_H
