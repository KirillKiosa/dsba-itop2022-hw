#include "videowindow.h"
#include "ui_videowindow.h"
#include "additionalwindow.h"
#include "video.h"
#include <QStandardItemModel>
#include <QStringListModel>
#include <vector>
#include "attributes.h"
VideoWindow::VideoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    createTable(videos);
}

VideoWindow::~VideoWindow()
{
    delete ui;
}
bool compare(const Video& v1, const Video& v2)
{
    if (v1.likes > v2.likes)
        return v1.likes > v2.likes;
    else if (v1.likes < v2.likes)
        return v1.likes > v2.likes;
    else
    {
        if (v1.title > v2.title)
            return v1.title > v2.title;
        else
            return v1.title >= v2.title;
    }
}
void VideoWindow::createTable(std::vector<Video> videos)
{
    std::sort(videos.begin(), videos.end(), compare);
    QString A = ui->lineEdit->text();
    int number = A.toInt(); ///
    model = new QStandardItemModel(0, 2, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Title"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Likes"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i].likes >= number)
        {
            model->insertRows(i,1);
            model->setData(model->index(i, 0), QString::fromStdString(videos[i].title));
            model->setData(model->index(i, 1), QString::number(videos[i].likes));
        }
        else
            break;
    }
    ui->tableView->setColumnWidth(0,300);

}

void VideoWindow::getData1(std::vector<Attributes> vec)
{
    std::map<std::string, std::pair<int, std::string>> artists;
    for (int i = 0; i < vec.size(); i++)
        artists[vec[i].title] = {vec[i].likes, vec[i].link};

    std::vector<Video> videos;
    //int i = 0;
    for (std::map<std::string, std::pair<int, std::string>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        Video vidos;
        vidos.title = it->first;
        vidos.likes = it->second.first;
        vidos.link = it->second.second;
        this->videos.push_back(vidos);
    }
}


void VideoWindow::on_pushButton_clicked()
{
    createTable(videos);
}


void VideoWindow::on_pushButton_2_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i].title == model->data(model->index(selectedRow, 0)).toString().toStdString())
        {
            ui->lineEdit_2->setText(QString::fromStdString(videos[i].link));
            break;
        }
    }
}

