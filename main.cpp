/*
Author: Adam Miller
Description: CPP file for the main function
Date: 2020-11-11
*/
#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
/*
Name: main
Description: The main function, setups up a mainwindow. Most "driving" of the code is done by user input
Parameter Descriptions: argc, argv unused
Return Description: N/A
*/
#include "NewsCategory.h"

int main(int argc, char *argv[])
{
    QFontDatabase::addApplicationFont(":/FreeSans.ttf");    //sets up the font for the app - required to ensure fonts display across platforms
    QApplication a(argc, argv);                             //creates the qt framework that all UI exists within
    QFont font = QFont("FreeSans",10,1);                    //sets up the font for the main window
    MainWindow w;                                           //sets up the main window
    w.setFont(font);
    w.show();                                               //shows the main window
    return a.exec();                                        //required by qt
}
