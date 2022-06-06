#include "filterwindow.h"
#include "ui_filterwindow.h"
#include "additionalwindow.h"
#include "attributes.h"
#include <vector>
#include <algorithm>
#include "filters.h"
#include <QStandardItemModel>
#include <QStringListModel>
FilterWindow::FilterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    showTable(filter);
}

FilterWindow::~FilterWindow()
{
    delete ui;
}

void FilterWindow::showTable(std::vector<Filters> filter)
{
    enum Months{January, February, March, April, May, June, July, August, September, October, November, December};
    std::map<std::string,Months> str2month;
    str2month["January"]  = Months::January;
    str2month["February"]  = Months::February;
    str2month["March"]  = Months::March;
    str2month["April"]  = Months::April;
    str2month["May"]  = Months::May;
    str2month["June"]  = Months::June;
    str2month["July"]  = Months::July;
    str2month["September"]  = Months::September;
    str2month["October"]  = Months::October;
    str2month["November"]  = Months::November;
    str2month["December"]  = Months::December;

    std::string month = ui->lineEdit->text().toStdString();
    Months m2 = str2month[month];
    int year = ui->lineEdit_2->text().toInt();
    int likes1 = ui->lineEdit_3->text().toInt();
    int views1 = ui->lineEdit_4->text().toInt();
    //ui->lineEdit_5->setText(QString::number(m2));

    model = new QStandardItemModel(0, 6, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Title"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Month"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Year"));
    model->setHorizontalHeaderItem(3, new QStandardItem("Likes"));
    model->setHorizontalHeaderItem(4, new QStandardItem("Views"));
    model->setHorizontalHeaderItem(5, new QStandardItem("Link"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    int a = 0;
    for (int i = 0; i < filter.size(); i++)
    {
        Months m1 = str2month[filter[i].month];
        bool localdate = 0;
        if (filter[i].year > year || (filter[i].year == year && m1 >= m2))
            localdate = 1;
        else if (month ==  "" && filter[i].year >= year)
            localdate = 1;
        bool localviews = (filter[i].views >= views1);
        bool locallikes = (filter[i].likes >= likes1);
        if (localdate == 1 && localviews == 1 && locallikes == 1)
        {
            model->insertRows(a,1);
            model->setData(model->index(a, 0), QString::fromStdString(filter[i].title));
            model->setData(model->index(a, 1), QString::fromStdString(filter[i].month));
            model->setData(model->index(a, 2), QString::number(filter[i].year));
            model->setData(model->index(a, 3), QString::number(filter[i].likes));
            model->setData(model->index(a, 4), QString::number(filter[i].views));
            model->setData(model->index(a, 5), QString::fromStdString(filter[i].link));
            a++;
        }
    }
    ui->lineEdit_5->setText(QString::number(a));

}
void FilterWindow::getData2(std::vector<Attributes> vec)
{
    std::vector<Filters> filter;
    for (int i = 0; i < vec.size(); i++)
    {
        Filters filt;
        filt.title = vec[i].title;
        int a = vec[i].date.find(" ");
        filt.month = vec[i].date.substr(0, a);
        filt.year = stoi(vec[i].date.substr(a+1));
        filt.likes = vec[i].likes;
        filt.views = vec[i].views;
        filt.link = vec[i].link;
        this->filter.push_back(filt);
    }
}


void FilterWindow::on_pushButton_clicked()
{
    showTable(filter);
}

