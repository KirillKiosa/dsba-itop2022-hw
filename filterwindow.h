#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QDialog>
#include "attributes.h"
#include <filters.h>
#include <vector>
#include <QStandardItemModel>
#include <QStringListModel>
#include <iostream>
namespace Ui {
class FilterWindow;
}

class FilterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = nullptr);
    ~FilterWindow();

    enum Months{January, February, March, April, May, June, July, August, September, October, November, December};
    void getData2(std::vector<Attributes> vec);
    void showTable(std::vector<Filters> filter);
private slots:
    void on_pushButton_clicked();

private:
    Ui::FilterWindow *ui;
    std::vector<Attributes> vec;
    std::vector<Filters> filter;
    QStandardItemModel* model;
    std::map<std::string,Months> str2month;

};

#endif // FILTERWINDOW_H
