#include "speakerwindow.h"
#include "ui_speakerwindow.h"
#include "attributes.h"
#include <map>
#include <vector>
#include <QFileDialog>
#include "speaker.h"
#include <algorithm>
#include <QStandardItemModel>
#include <QStringListModel>
#include "talkswindow.h"
SpeakerWindow::SpeakerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeakerWindow)
{
    ui->setupUi(this);
    createTable(newArtists);
}

SpeakerWindow::~SpeakerWindow()
{
    delete ui;
}

bool compare(const Speaker& s1, const Speaker& s2)
{
    if (s1.talks > s2.talks)
        return s1.talks > s2.talks;
    else if (s1.talks < s2.talks)
        return s1.talks > s2.talks;
    else
    {
        if (s1.author.size() > s2.author.size())
            return s1.author.size() > s2.author.size();
        else
            return s1.author.size() >= s2.author.size();
    }

}
void SpeakerWindow::createTable(std::vector<Speaker> newArtists)
{
    std::sort(newArtists.begin(), newArtists.end(), compare);
    QString A = ui->lineEdit->text();
    int a = A.toInt(); ///
    model = new QStandardItemModel(0, 2, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Author"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Number of talks"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    for(int i = 0; i < a; i++)
    {
        model->insertRows(i,1);
        model->setData(model->index(i, 0), QString::fromStdString(newArtists[i].author));
        model->setData(model->index(i, 1), QString::number(newArtists[i].talks));
    }
    ui->tableView->setColumnWidth(0,300);
    ui->tableView->setColumnWidth(1,300);
}

void SpeakerWindow::getData(std::vector<Attributes> vec)
{
    std::map<std::string, std::vector<std::string>> artists;
    for (int i = 0; i < vec.size(); i++)
        artists[vec[i].author].push_back(vec[i].title);

    std::vector<Speaker> newArtists;

    for(std::map<std::string, std::vector<std::string>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        Speaker art;
        art.author = it->first;
        art.talks = it->second.size();
        art.titles = it->second;
        this->newArtists.push_back(art);
    }
}
void SpeakerWindow::on_pushButton_clicked()
{
    createTable(newArtists);
}


void SpeakerWindow::on_pushButton_2_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    int Row = 0;
    for (int i = 0; i < newArtists.size(); i++)
    {
        if (newArtists[i].author == model->data(model->index(selectedRow, 0)).toString().toStdString())
        {
            Row = i;
            break;
        }
    }
    TalksWindow talker;
    talker.getData2(&newArtists[Row]);
    talker.setModal(true);
    talker.exec();
}

