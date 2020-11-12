/*
Author: Dhyey Patel
Description: CPP for NewsWindow, the window that displays information about the news
Date: 2020-11-11
*/
#include "newswindow.h"
#include "ui_newswindow.h"

/*
Name: NewsWindow THIS ENTIRE CLASS NEEDS TO BE COMPLETED- JUST A TEMPLATE IS BUILD SO FAR
Description: This is a constructor to create an instance of the NewsWindow class
Parameter Descriptions: It needs a reference to the main window, and needs to get its widgets
Return Description: N/A
*/
NewsWindow::NewsWindow(MainWindow * Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWindow)
{
    ui->setupUi(this);
    parentWindow = Window;

}

/*
Name: ~NewsWindow
Description: This is a deconstructor to destroy the instance of the NewsWindow class
Parameter Descriptions: N/A
Return Description: N/A
*/
NewsWindow::~NewsWindow()
{
    // Delete the ui created in the constructor
    delete ui;
}

/*
Name: on_BackButton_clicked
Description: Method will execute when the back button is clicked
Parameter Descriptions: N/A
Return Description: N/A
*/
void NewsWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    parentWindow->show();
    close();

}
