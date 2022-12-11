#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <QMainWindow>
#include <QtSql>
#include <QListWidgetItem>
#include "recipeeditor.h"
#include "recipeviewer.h"

namespace Ui {
class RecipeBook;
}

class RecipeBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit RecipeBook(QWidget *parent = 0);
    ~RecipeBook();

private:
    Ui::RecipeBook *ui;
    QSqlDatabase db;
    RecipeEditor *editor;
    RecipeViewer *viewer;

private slots:
    void search(QString str);
    void on_addRecipeButton_clicked();
    void on_recipeList_itemClicked(QListWidgetItem *item);
    void updateList();

signals:
    void send_to_viewer(QString);
};

void createDatabase();

#endif // RECIPEBOOK_H
