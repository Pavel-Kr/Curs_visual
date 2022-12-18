#ifndef STEPSVIEWER_H
#define STEPSVIEWER_H

#include <QWidget>
#include <QVector>

namespace Ui {
class StepsViewer;
}

class StepsViewer : public QWidget
{
    Q_OBJECT

public:
    explicit StepsViewer(QWidget *parent = 0);
    ~StepsViewer();
    void setRecipe(int recipe_id);

private slots:
    void on_nextButton_clicked();

    void on_prevButton_clicked();

private:
    Ui::StepsViewer *ui;
    QStringList descriptions;
    QStringList numbers;
    QStringList photos;
    int index;
    void setPhoto();
};

#endif // STEPSVIEWER_H
