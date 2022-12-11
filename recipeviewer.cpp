#include "recipeviewer.h"
#include "ui_recipeviewer.h"
#include <QDebug>
#include <QtSql>

RecipeViewer::RecipeViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeViewer)
{
    ui->setupUi(this);
    editor = new RecipeEditor();
    sViewer = new StepsViewer();
}

RecipeViewer::~RecipeViewer()
{
    delete ui;
}

void RecipeViewer::setRecipe(QString str)
{
    recipe = str;
    QStringList list = str.split("|");
    QString header = list[0];
    QString name = header.split("&").at(0);
    QString desc = header.split("&").at(1);
    ui->recipeNameLabel->setText(name);
    ui->recipeDescriptionLabel->setText(desc);
    QLayoutItem *child;
    while((child = ui->ingredientsList->takeAt(0)) != nullptr){
        delete child->widget();
        delete child;
    }
    for(int i = 1; i < list.size(); i++){
        QString ingredient = list[i];
        QString i_name = ingredient.split("&").at(0);
        QString quantity = ingredient.split("&").at(1);
        QLabel *label = new QLabel();
        label->setText(i_name + " - " + quantity);
        ui->ingredientsList->addWidget(label);
    }
}

void RecipeViewer::on_recipeDeleteButton_clicked()
{
    QSqlQuery query;
    bool ok = query.prepare("SELECT id FROM recipes WHERE name = :name");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":name",ui->recipeNameLabel->text());
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.next();
    int recipe_id = query.value(0).toInt(&ok);
    if(!ok){
        qDebug()<<query.lastError();
    }
    ok = query.prepare("DELETE FROM recipes WHERE name = :name");
    if(!ok){
        qDebug()<<"Prepare"<<query.lastError();
    }
    query.bindValue(":name",ui->recipeNameLabel->text());
    ok = query.exec();
    if(!ok){
        qDebug()<<"Exec"<<query.lastError();
    }
    ok = query.prepare("DELETE FROM recipe_to_ingredient WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<"Prepare"<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<"Exec"<<query.lastError();
    }
    close();
    emit recipeChanged();
}

void RecipeViewer::on_recipeEditButton_clicked()
{
    editor->show();
    editor->setRecipe(recipe);
    close();
}

void RecipeViewer::on_toStepsViewerButton_clicked()
{
    sViewer->show();
}
