#ifndef ADDITIONALWINDOW_H
#define ADDITIONALWINDOW_H

#include <QDialog>
#include "attributes.h"
namespace Ui {
class AdditionalWindow;
}

class AdditionalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdditionalWindow(QWidget *parent = nullptr);
    ~AdditionalWindow();

    void giveData(std::vector<Attributes> vec);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AdditionalWindow *ui;
    std::vector<Attributes> vec;
    std::vector<Attributes> vec1;
};

#endif // ADDITIONALWINDOW_H
