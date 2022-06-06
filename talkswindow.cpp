#include "talkswindow.h"
#include "ui_talkswindow.h"
#include "speaker.h"
#include <QStringListModel>
#include <QStandardItemModel>
#include <vector>
TalksWindow::TalksWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TalksWindow)
{
    ui->setupUi(this);
}

TalksWindow::~TalksWindow()
{
    delete ui;
}
void TalksWindow::getData2(Speaker *art)
{
    QStringList list;
    for(int i = 0; i < art->titles.size(); i++)
        list << QString::fromStdString(art->titles[i]);

    this->model = new QStringListModel(this);
    this->model->setStringList(list);
    ui->listView->setModel(model);
    this->ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
