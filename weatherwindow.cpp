#include <iostream>
#include <vector>
#include <QString>
#include <QMessageBox>


#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "WeatherCategory.h"
#include "errorbox.h"
#include "mainwindow.h"

using namespace std;
WeatherWindow::WeatherWindow(MainWindow *Window, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);
    dayCounter = 0;
    cORf = 0;
    ui->prevButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->celcButton->setEnabled(false);
    ui->farenButton->setEnabled((false));
    parentWindow = Window;
}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}

void WeatherWindow::on_searchBar_returnPressed(){
    category.search(ui->searchBar->text().toStdString());
    r = new WeatherRecord(category.getRecords()[0]);
    updateDisplay();
    ui->prevButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->celcButton->setEnabled(true);
    ui->farenButton->setEnabled((true));

}
void WeatherWindow::on_BackButton_clicked(){
    parentWindow->close();
    parentWindow = new MainWindow();
    parentWindow->show();
    close();

}

void WeatherWindow::updateDisplay(){
    double temp;
    if (cORf == 0){
        temp = r->getDays()[dayCounter].getTempFaren();
    } else {
        temp = r->getDays()[dayCounter].getTempCelsius();
    }
    ui->temp->display(temp);
    ui->locationLabel->setText((ui->searchBar->text()));
    ui->dateLabel->setText(QString::fromStdString(r->getDays()[dayCounter].getDate().getStr()));
    ui->descLabel->setText(QString::fromStdString(r->getDays()[dayCounter].getDescription()));
}



void WeatherWindow::on_celcButton_clicked()
{
    cORf = 1;
    updateDisplay();
}

void WeatherWindow::on_farenButton_clicked()
{
    cORf = 0;
    updateDisplay();
}

void WeatherWindow::on_prevButton_clicked()
{
    if(dayCounter == 0){
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no previous day!");
        error->show();

        return;
    }
    dayCounter --;
    updateDisplay();
}

void WeatherWindow::on_nextButton_clicked()
{
    if(dayCounter == r->getDays().size()-1){
        ErrorBox * error = new ErrorBox();
        QFont font = QFont("FreeSans",10,1);
        error->setFont(font);
        error->setWindowTitle("Error");
        error->error("There is no next day!");
        error->show();
        return;
    }
    dayCounter++;
    updateDisplay() ;
}
