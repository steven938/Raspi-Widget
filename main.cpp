#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QFontDatabase::addApplicationFont(":/FreeSans.ttf");
    QApplication a(argc, argv);
    QFont font = QFont("FreeSans",10,1);
    MainWindow w;
    w.setFont(font);
    w.showMaximized();
    return a.exec();
}
