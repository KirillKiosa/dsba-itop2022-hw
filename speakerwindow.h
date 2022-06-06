#ifndef SPEAKERWINDOW_H
#define SPEAKERWINDOW_H

#include <QDialog>
#include "attributes.h"
#include "speaker.h"
#include <QStandardItemModel>
#include <QStringListModel>
#include "additionalwindow.h"
namespace Ui {
class SpeakerWindow;
}

class SpeakerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SpeakerWindow(QWidget *parent = nullptr);
    ~SpeakerWindow();

    void getData(std::vector<Attributes> vec);
    //void newData();
    void createTable(std::vector<Speaker> newArtists);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SpeakerWindow *ui;
    int a;
    std::vector<Attributes> vec;
    std::vector<Speaker> newArtists;
    QStandardItemModel* model;
};

#endif // SPEAKERWINDOW_H
