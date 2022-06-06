#include "additionalwindow.h"
#include "ui_additionalwindow.h"
#include "speakerwindow.h"
#include "secondwindow.h"
#include <vector>
#include "videowindow.h"
#include "filterwindow.h"
AdditionalWindow::AdditionalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdditionalWindow)
{
    ui->setupUi(this);
}

AdditionalWindow::~AdditionalWindow()
{
    delete ui;
}
std::vector<Attributes> vec1;
void AdditionalWindow::giveData(std::vector<Attributes> vec)
{
    vec1 = vec;
}
void AdditionalWindow::on_pushButton_clicked()
{
    SpeakerWindow speak;
    speak.getData(vec1);
    speak.exec();
}


void AdditionalWindow::on_pushButton_2_clicked()
{
    VideoWindow vid;
    vid.getData1(vec1);
    vid.exec();
}


void AdditionalWindow::on_pushButton_3_clicked()
{
    FilterWindow filt;
    filt.getData2(vec1);
    filt.exec();
}

