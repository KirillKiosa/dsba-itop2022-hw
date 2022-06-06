#ifndef AUTHORINFO_H
#define AUTHORINFO_H

#include <QDialog>
#include <QPainter>
#include "helpwindow.h"
namespace Ui {
class AuthorInfo;
}

class AuthorInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorInfo(QWidget *parent = nullptr);
    ~AuthorInfo();

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_pushButton_clicked();

private:
    Ui::AuthorInfo *ui;
};

#endif // AUTHORINFO_H
