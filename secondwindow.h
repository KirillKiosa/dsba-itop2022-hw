#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <vector>
#include "attributes.h"


namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void ListOfTalks();



private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_6_clicked();

private:
    Ui::SecondWindow *ui;
    std::vector<Attributes> vec;
    QStringListModel *model;
};

#endif // SECONDWINDOW_H
