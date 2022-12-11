#include "recipeeditor.h"
#include "ui_recipeeditor.h"
#include <QDebug>

RecipeEditor::RecipeEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeEditor)
{
    ui->setupUi(this);
    connect(ui->recipeNameEdit,SIGNAL(textChanged(QString)),this,SLOT(enableSaveButton()));
    enableSaveButton();
    on_addIngredientButton_clicked();
    sEditor = new StepsEditor();
    connect(this,SIGNAL(stepsEditButton_clicked(int)),sEditor,SLOT(setSteps(int)));
}

RecipeEditor::~RecipeEditor()
{
    delete ui;
}

void RecipeEditor::setRecipe(QString str)
{
    QStringList list = str.split("|");
    QString header = list[0];
    QString name = header.split("&").at(0);
    QString desc = header.split("&").at(1);
    oldName = name;
    ui->recipeNameEdit->setText(name);
    ui->descriptionEdit->setPlainText(desc);
    for(int i=0;i<buttons.size();i++){
        QHBoxLayout *item = (QHBoxLayout*)ui->ingredientsList->takeAt(i);
        QLayoutItem* child;
        while((child = item->takeAt(0)) != nullptr){
            delete child->widget();
            delete child;
        }
        delete item;
        buttons.removeAt(i);
    }
    for(int i = 1; i < list.size(); i++){
        QString ingredient = list[i];
        QString i_name = ingredient.split("&").at(0);
        QString quantity = ingredient.split("&").at(1);
        addIngredient(i_name, quantity);
    }
}

void RecipeEditor::on_addIngredientButton_clicked()
{
    addIngredient();
}

void RecipeEditor::enableSaveButton()
{
    ui->saveButton->setEnabled(!ui->recipeNameEdit->text().isEmpty() && !ui->recipeNameEdit->text().isNull());
}

bool ingredientExists(QString name){
    QSqlQuery query;
    bool ok = query.prepare("SELECT id FROM ingredients WHERE name = :name");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":name",name);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    return query.next();
}

int getId(QString table, QString column, QString value){
    QSqlQuery query;
    QString str = "SELECT id FROM " + table + " WHERE " + column + " = :value";
    bool ok = query.prepare(str);
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":value",value);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.next();
    int id = query.value(0).toInt(&ok);
    if(!ok){
        qDebug()<<query.lastError();
    }
    return id;
}

void deleteFrom(QString table, QString column, QString value){
    QSqlQuery query;
    QString str = "DELETE FROM " + table + " WHERE " + column + " = :value";
    bool ok = query.prepare(str);
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":value",value);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
}

void RecipeEditor::on_saveButton_clicked()
{
    QString recipeName = ui->recipeNameEdit->text();
    QSqlQuery query;
    QString description = ui->descriptionEdit->toPlainText();
    bool ok;
    if(oldName.isEmpty()){
        qDebug()<<"is empty";
        ok = query.prepare("INSERT INTO recipes (name, description, name_lower)"
                             "VALUES (?,?,?);");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(0,recipeName);
        query.bindValue(1,description);
        query.bindValue(2,recipeName.toLower());
        ok = query.exec();
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    else{
        qDebug()<<oldName;
        ok = query.prepare("UPDATE recipes "
                                "SET name = :name, description = :desc, name_lower = :name_l "
                                "WHERE name = :old_name");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(":name",recipeName);
        query.bindValue(":desc",description);
        query.bindValue(":name_l",recipeName.toLower());
        query.bindValue(":old_name",oldName);
        ok = query.exec();
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    int recipe_id = getId("recipes","name",recipeName);
    deleteFrom("recipe_to_ingredient","recipe_id",QString::number(recipe_id));
    //deleteFrom("recipes","name",oldName);
    for(int i=0;i<ui->ingredientsList->count();i++){
        QHBoxLayout *ingredient = (QHBoxLayout*)ui->ingredientsList->itemAt(i);
        QLineEdit *nameEdit = (QLineEdit*)ingredient->itemAt(0)->widget();
        QString name = nameEdit->text();
        if(!ingredientExists(name)){
            ok = query.prepare("INSERT INTO ingredients (name, name_lower)"
                          "VALUES (:name, :name_lower);");
            if(!ok){
                qDebug()<<query.lastError();
            }
            query.bindValue(":name",name);
            query.bindValue(":name_lower",name.toLower());
            ok = query.exec();
            if(!ok){
                qDebug()<<query.lastError();
            }
        }
        int ingredient_id = getId("ingredients","name",name);
        QLineEdit *quantityEdit = (QLineEdit*)ingredient->itemAt(1)->widget();
        QString quantity = quantityEdit->text();
        ok = query.prepare("INSERT INTO recipe_to_ingredient (recipe_id, ingredient_id, quantity)"
                      "VALUES (:rid, :iid, :quantity);");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(":rid",recipe_id);
        query.bindValue(":iid",ingredient_id);
        query.bindValue(":quantity",quantity);
        ok = query.exec();
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    emit recipeChanged();
    close();
}

void RecipeEditor::deleteIngredient()
{
    QPushButton *senderButton = (QPushButton*)sender();
    for(int i=0;i<buttons.size();i++){
        if(senderButton == buttons[i]){
            QHBoxLayout *item = (QHBoxLayout*)ui->ingredientsList->takeAt(i);
            QLayoutItem* child;
            while((child = item->takeAt(0)) != nullptr){
                delete child->widget();
                delete child;
            }
            delete item;
            buttons.removeAt(i);
            break;
        }
    }
}

void RecipeEditor::on_stepsEditButton_clicked()
{
    sEditor->show();
    int recipe_id = getId("recipes","name",oldName);
    emit stepsEditButton_clicked(recipe_id);
}

void RecipeEditor::addIngredient(QString name, QString quantity)
{
    QHBoxLayout *item = new QHBoxLayout();
    QLineEdit *nameEdit = new QLineEdit();
    nameEdit->setPlaceholderText("Название");
    nameEdit->setText(name);
    QLineEdit *quantityEdit = new QLineEdit();
    quantityEdit->setPlaceholderText("Количество");
    quantityEdit->setText(quantity);
    QPushButton *deleteButton = new QPushButton();
    deleteButton->setText("Удалить");
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteIngredient()));
    item->addWidget(nameEdit);
    item->addWidget(quantityEdit);
    item->addWidget(deleteButton);
    buttons.push_back(deleteButton);
    ui->ingredientsList->insertLayout(ui->ingredientsList->count(),item);
}
