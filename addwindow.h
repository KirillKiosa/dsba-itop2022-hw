#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include "attributes.h"
namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();
    void setPointers(Attributes *attr, QStringListModel *model);
private slots:
    void on_pushButton_clicked();

private:
    Ui::AddWindow *ui;
    Attributes *attr;
    QStringListModel *model;
};

#endif // ADDWINDOW_H
