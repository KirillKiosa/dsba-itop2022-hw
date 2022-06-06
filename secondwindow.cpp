#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "addwindow.h"
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include<algorithm>
#include "attributes.h"
#include "additionalwindow.h"
#include "speakerwindow.h"
SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    ListOfTalks();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
void SecondWindow::ListOfTalks()
{
    std::ifstream inputFile("data.csv");
    std::string line, token;
    std::getline(inputFile, line);
    while(std::getline(inputFile, line))
    {
        std::vector<std::string> lineAsVector;
        int countCommas = 0;
        int i = line.size() - 1;
        while (countCommas < 5)
        {
            if (line[i] == ',')
                countCommas++;
            i--;
        }
        lineAsVector.push_back(line.substr(0, i+1));
        std::istringstream ss(line.substr(i+2));
        while(std::getline(ss, token, ','))
            lineAsVector.push_back(token);
        Attributes attr;
        attr.title = lineAsVector[0];
        attr.author = lineAsVector[1];
        attr.date = lineAsVector[2];
        attr.views = stoi(lineAsVector[3]);
        attr.likes = stoi(lineAsVector[4]);
        attr.link = lineAsVector[5];
        this->vec.push_back(attr);

    }
    inputFile.close();
    QStringList list;
    for(int i = 0; i < vec.size(); i++)
    {
        list << QString::fromStdString(vec[i].title);
    }
    this->model = new QStringListModel(this);
    this->model->setStringList(list);
    ui->listView->setModel(model);
    ui->lineEdit->setText(QString::number(vec.size())); // a number of titles
    this->ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void SecondWindow::on_listView_clicked(const QModelIndex &index)
{
    int number = this->ui->listView->currentIndex().row();
    ui->title->setText(QString::fromStdString(vec[number].title));
    ui->author->setText(QString::fromStdString(vec[number].author));
    ui->date->setText(QString::fromStdString(vec[number].date));
    ui->views->setText(QString::number(vec[number].views));
    ui->likes->setText(QString::number(vec[number].likes));
    ui->link->setText(QString::fromStdString(vec[number].link));
}


void SecondWindow::on_pushButton_5_clicked()
{
    int number = this->ui->listView->currentIndex().row();
    this->vec[number].title = ui->title->text().toStdString();
    this->vec[number].author = ui->author->text().toStdString();
    this->vec[number].date = ui->date->text().toStdString();
    this->vec[number].views = ui->views->text().toInt();
    this->vec[number].likes = ui->likes->text().toInt();
    this->vec[number].link = ui->link->text().toStdString();

    // update model

    QModelIndex index = model->index(number, 0, QModelIndex());  // "iterator"
    model->setData(index, ui->title->text());  // insert text at posi,ion index

}


void SecondWindow::on_pushButton_clicked()
{
    AddWindow addW;
    Attributes newAttr;
    ui->lineEdit->setText(QString::number(vec.size() + 1));
    this->vec.push_back(newAttr);
    addW.setPointers(&vec[vec.size() - 1], model);
    addW.setModal(true);
    addW.exec();
}


void SecondWindow::on_pushButton_2_clicked()
{
    int talkNumber = this->ui->listView->currentIndex().row();
    ui->lineEdit->setText(QString::number(vec.size() - 1));
    this->model->removeRows(talkNumber, 1);

    ui->title->setText(QString::fromStdString("no information"));
    ui->author->setText(QString::fromStdString("no information"));
    ui->date->setText(QString::fromStdString("no information"));
    ui->views->setText(QString::fromStdString("no information"));
    ui->likes->setText(QString::fromStdString("no information"));
    ui->link->setText(QString::fromStdString("no information"));

    std::vector<Attributes>::iterator it = this->vec.begin() + talkNumber;
    this->vec.erase(it);
}

void SecondWindow::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", ".csv");

    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    f.write("Author,Title,Date,Views,Likes,Link\n");

    for(int i = 0; i < vec.size(); i++)
    {
        std::stringstream ss;
        ss << vec[i].title << "," << vec[i].author << "," << vec[i].date << "," << vec[i].views << "," << vec[i].likes << "," << vec[i].link <<'\n';
        f.write(ss.str().c_str());
    }
    f.close();
}




void SecondWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Load file", "");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    this->vec.clear();
    this->model->removeRows(0, this->model->rowCount());

    file.readLine();
    while(!file.atEnd())
    {
        std::string line = file.readLine().toStdString();
        std::string token;

        std::vector<std::string> lineAsVector;
        int countCommas = 0;
        int i = line.size() - 1;
        while (countCommas < 5)
        {
            if (line[i] == ',')
                countCommas++;
            i--;
        }
        lineAsVector.push_back(line.substr(0, i+1));
        std::istringstream ss(line.substr(i+2));
        while(std::getline(ss, token, ','))
            lineAsVector.push_back(token);
        Attributes attr;
        attr.title = lineAsVector[0];
        attr.author = lineAsVector[1];
        attr.date = lineAsVector[2];
        attr.views = stoi(lineAsVector[3]);
        attr.likes = stoi(lineAsVector[4]);
        attr.link = lineAsVector[5];
        this->vec.push_back(attr);

    }
    ui->lineEdit->setText(QString::number(vec.size()));
    file.close();
    QStringList list;
    for(int i = 0; i < vec.size(); i++)
    {
        list << QString::fromStdString(vec[i].title);
    }
    this->model->setStringList(list);
}


void SecondWindow::on_pushButton_6_clicked()
{
    AdditionalWindow addW;
    addW.giveData(vec);
    addW.exec();

}

