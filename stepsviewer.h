#ifndef STEPSVIEWER_H
#define STEPSVIEWER_H

#include <QWidget>

namespace Ui {
class StepsViewer;
}

class StepsViewer : public QWidget
{
    Q_OBJECT

public:
    explicit StepsViewer(QWidget *parent = 0);
    ~StepsViewer();

private:
    Ui::StepsViewer *ui;
};

#endif // STEPSVIEWER_H
