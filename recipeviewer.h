#ifndef RECIPEVIEWER_H
#define RECIPEVIEWER_H

#include <QWidget>
#include "recipeeditor.h"
#include "stepsviewer.h"

namespace Ui {
class RecipeViewer;
}

class RecipeViewer : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeViewer(QWidget *parent = 0);
    ~RecipeViewer();

private:
    Ui::RecipeViewer *ui;
    QString recipe;
    RecipeEditor *editor;
    StepsViewer *sViewer;

public slots:
    void setRecipe(QString str);
private slots:
    void on_recipeDeleteButton_clicked();
    void on_recipeEditButton_clicked();

    void on_toStepsViewerButton_clicked();

signals:
    void recipeChanged();

};

#endif // RECIPEVIEWER_H
