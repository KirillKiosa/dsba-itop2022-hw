#include "helpwindow.h"
#include "ui_helpwindow.h"
#include "mainwindow.h"
#include "authorinfo.h"
//#include "GlobalVariables.h"
HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_pushButton_2_clicked()
{
    this->close();
}


void HelpWindow::on_pushButton_clicked()
{
    AuthorInfo info;
    info.exec();
}

