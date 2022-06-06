
#include "speakerswindow.h"
#include "ui_speakerswindow.h"
#include "additionalwindow.h"
#include "attributes.h"
#include "secondwindow.h"
#include <vector>
#include <map>
SpeakersWindow::SpeakersWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeakersWindow)
{

    ui->setupUi(this);
}
