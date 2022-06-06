#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"
#include "helpwindow.h"
#include "projectinfo.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuProject->addAction("About",this,SLOT(openAbout()));
}
void MainWindow::openAbout()
{
    // Opens an AboutWindow when the user clicks the "About" option in the menu bar

    ProjectInfo pr;
    pr.setVisible(true);
    pr.exec();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    SecondWindow secWin;
    secWin.setModal(true);
    secWin.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    HelpWindow helpW;
    helpW.exec();
}

