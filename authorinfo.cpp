#include "authorinfo.h"
#include "ui_authorinfo.h"
#include "helpwindow.h"
#include "GlobalVariables.h"
AuthorInfo::AuthorInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorInfo)
{
    ui->setupUi(this);
    if (!GlobalVariables::studentId.isEmpty())
        ui->lineEdit->setText(GlobalVariables::studentId);
}

AuthorInfo::~AuthorInfo()
{
    delete ui;
}

void AuthorInfo::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    QPoint a;
    a.setX(90);
    a.setY(270);

    QPoint b;
    b.setX(170);
    b.setY(270);

    QPoint c;
    c.setX(130);
    c.setY(90);

    QPoint d;
    d.setX(50);
    d.setY(160);

    QPoint e;
    e.setX(210);
    e.setY(160);
    painter.setPen(Qt::red);
    painter.drawLine(a,c);
    painter.drawLine(b,c);
    painter.drawLine(d,b);
    painter.drawLine(a,e);
    painter.drawLine(d,e);
    painter.end();
}
void AuthorInfo::on_pushButton_clicked()
{
    GlobalVariables::studentId = ui->lineEdit->text();
    this->close();

}



