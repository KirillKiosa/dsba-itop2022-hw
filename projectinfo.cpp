#include "projectinfo.h"
#include "ui_projectinfo.h"

ProjectInfo::ProjectInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectInfo)
{
    ui->setupUi(this);
}

ProjectInfo::~ProjectInfo()
{
    delete ui;
}
