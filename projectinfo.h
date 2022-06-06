#ifndef PROJECTINFO_H
#define PROJECTINFO_H

#include <QDialog>

namespace Ui {
class ProjectInfo;
}

class ProjectInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectInfo(QWidget *parent = nullptr);
    ~ProjectInfo();

private:
    Ui::ProjectInfo *ui;
};

#endif // PROJECTINFO_H
