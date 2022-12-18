#include "recipeviewer.h"
#include "ui_recipeviewer.h"
#include "functions.h"
#include <QDebug>
#include <QtSql>

RecipeViewer::RecipeViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeViewer)
{
    ui->setupUi(this);
    sViewer = new StepsViewer();
    setProperty("window",true);
}

RecipeViewer::~RecipeViewer()
{
    delete ui;
}

void RecipeViewer::setEditor(RecipeEditor *editor)
{
    this->editor = editor;
}

void RecipeViewer::deletePhotos(int recipe_id)
{
    QSqlQuery query;
    bool ok = query.prepare("SELECT photo FROM photos WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    while (query.next()) {
        QString photo = "img/" + query.value(0).toString();
        if(QFile::exists(photo)){
            QFile::remove(photo);
        }
    }
    deleteFrom("photos","recipe_id",QString::number(recipe_id));
    ok = query.prepare("SELECT photo FROM steps WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    while (query.next()) {
        QString photo = "img/" + query.value(0).toString();
        QFile::remove(photo);
    }
}

void RecipeViewer::setRecipe(QString str)
{
    recipe = str;
    QStringList list = str.split("|");
    QString header = list[0];
    QString name = header.split("&").at(0);
    QString desc = header.split("&").at(1);
    QString photo = header.split("&").at(2);
    this->photo = photo;
    if(photo.isEmpty()){
        photo = ":/ico/ico/camera.png";
        ui->photoLabel->setScaledContents(false);
    }
    else{
        photo = "img/" + photo;
        ui->photoLabel->setScaledContents(true);
    }
    ui->recipeNameLabel->setText(name);
    ui->recipeDescriptionLabel->setText(desc);
    ui->photoLabel->setPixmap(QPixmap::fromImage(QImage(photo)));
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
        QString str = i_name;
        if(!quantity.isEmpty()){
            str += " - " + quantity;
        }
        label->setText(str);
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
    deleteFrom("recipes","name",ui->recipeNameLabel->text());
    deleteFrom("recipe_to_ingredient","recipe_id",QString::number(recipe_id));
    deletePhotos(recipe_id);
    deleteFrom("steps","recipe_id",QString::number(recipe_id));
    if(!photo.isEmpty()){
        QFile::remove("img/" + photo);
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
    QString name = ui->recipeNameLabel->text();
    int id = getId("recipes","name",name);
    sViewer->setRecipe(id);
}
