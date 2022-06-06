#ifndef SPEAKERSWINDOW_H
#define SPEAKERSWINDOW_H

#include <QDialog>
#include "attributes.h"
#include <vector>

namespace Ui {
class SpeakersWindow;
}

class SpeakersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SpeakersWindow(QWidget *parent = nullptr);
    ~SpeakersWindow();


private:
    Ui::SpeakersWindow *ui;
    std::vector<Attributes> vec;
};

#endif // SPEAKERSWINDOW_H
