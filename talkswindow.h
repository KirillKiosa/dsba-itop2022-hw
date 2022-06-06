#ifndef TALKSWINDOW_H
#define TALKSWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include "speaker.h"
namespace Ui {
class TalksWindow;
}

class TalksWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TalksWindow(QWidget *parent = nullptr);
    ~TalksWindow();

    void getData2(Speaker *art);
private:
    Ui::TalksWindow *ui;
    std::vector<Speaker> newArtists;
    QStringListModel *model;
    Speaker *art;
};

#endif // TALKSWINDOW_H
