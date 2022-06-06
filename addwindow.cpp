#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}
void AddWindow::setPointers(Attributes *attr, QStringListModel *model)
{
    this->attr = attr;
    this->model = model;
}

void AddWindow::on_pushButton_clicked()
{
    this->attr->title = ui->lineEdit->text().toStdString();
    this->attr->author = ui->lineEdit_2->text().toStdString();
    this->attr->date = ui->lineEdit_3->text().toStdString();
    this->attr->views = ui->lineEdit_4->text().toInt();
    this->attr->likes = ui->lineEdit_5->text().toInt();
    this->attr->link = ui->lineEdit_6->text().toStdString();

    int row = model->rowCount();
    model->insertRows(row, 1);
    QModelIndex index = model->index(row, 0, QModelIndex());
    model->setData(index, ui->lineEdit->text());
    this->close();
}

