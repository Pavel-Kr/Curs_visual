#include "stepsviewer.h"
#include "ui_stepsviewer.h"

StepsViewer::StepsViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepsViewer)
{
    ui->setupUi(this);
}

StepsViewer::~StepsViewer()
{
    delete ui;
}
