#ifndef STEPSEDITOR_H
#define STEPSEDITOR_H

#include <QWidget>
#include <QVector>
#include <QPushButton>

namespace Ui {
class StepsEditor;
}

class StepsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit StepsEditor(QWidget *parent = 0);
    ~StepsEditor();

private slots:

    void on_addStepButton_clicked();
    void deleteStepSlot();
    void on_saveButton_clicked();

public slots:
    void setSteps(int recipe_id);

private:
    Ui::StepsEditor *ui;
    void addStep(QString desc = "");
    void deleteStepAt(int index);
    QVector<QPushButton*> buttons;
    int recipe_id;
};

#endif // STEPSEDITOR_H
