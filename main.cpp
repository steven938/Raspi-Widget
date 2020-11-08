#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QFontDatabase::addApplicationFont(":/FreeSans.ttf");
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();
    return a.exec();
}
