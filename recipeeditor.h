#ifndef RECIPEEDITOR_H
#define RECIPEEDITOR_H

#include <QWidget>
#include <QtSql>
#include <QVector>
#include <QPushButton>
#include "stepseditor.h"

namespace Ui {
class RecipeEditor;
}

class RecipeEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeEditor(QWidget *parent = 0);
    ~RecipeEditor();
    void setRecipe(QString str);

private slots:
    void on_addIngredientButton_clicked();
    void enableSaveButton();
    void on_saveButton_clicked();
    void deleteIngredient();

    void on_stepsEditButton_clicked();

private:
    Ui::RecipeEditor *ui;
    QVector<QPushButton*> buttons;
    QString oldName;
    QString oldPhoto;
    StepsEditor *sEditor;
    QCompleter *completer;
    void addIngredient(QString name = "", QString quantity = "");
    void saveName(QString name, QString description);
    void savePhoto(QString photo, int recipe_id);
    void saveIngredient(QString name, QString quantity, int recipe_id);
    QStringList getIngredients();
    void refreshCompleter();

signals:
    void recipeChanged();
    void stepsEditButton_clicked(int);
};

#endif // RECIPEEDITOR_H
