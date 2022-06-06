#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QDialog>
#include "attributes.h"
#include "additionalwindow.h"
#include <QStandardItemModel>
#include <QStringListModel>
#include "video.h"
#include <vector>
namespace Ui {
class VideoWindow;
}

class VideoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();

    void createTable(std::vector<Video> videos);
    void getData1(std::vector<Attributes> vec);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::VideoWindow *ui;
    int number;
    std::vector<Attributes> vec;
    std::vector<Video> videos;
    QStandardItemModel* model;
};

#endif // VIDEOWINDOW_H
