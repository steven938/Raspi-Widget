#include <iostream>
#include <vector>
#include <QString>
#include <QMessageBox>


#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "WeatherCategory.h"

using namespace std;
WeatherWindow::WeatherWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);
    dayCounter = 0;
    cORf = 0;

}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}

void WeatherWindow::on_searchBar_returnPressed(){
    category.search(ui->searchBar->text().toStdString());
    r = new WeatherRecord(category.getRecords()[0]);
    updateDisplay();



}
void WeatherWindow::on_BackButton_clicked(){
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
        QMessageBox messageBox;
        QFont font = QFont("FreeSans",10,1);
        messageBox.setFont(font);
        messageBox.critical(0,"Error","There is no previous day !");
        messageBox.setFixedSize(500,200);
        return;
    }
    dayCounter --;
    updateDisplay();
}

void WeatherWindow::on_nextButton_clicked()
{
    if(dayCounter == r->getDays().size()-1){
        QMessageBox messageBox;
        QFont font = QFont("FreeSans",10,1);
        messageBox.setFont(font);
        messageBox.critical(0,"Error","There is no next day !");
        messageBox.setFixedSize(500,200);
        return;
    }
    dayCounter++;
    updateDisplay() ;
}
