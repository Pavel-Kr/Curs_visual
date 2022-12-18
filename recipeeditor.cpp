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
    QStringList ingredients = getIngredients();
    completer = new QCompleter(ingredients,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    on_addIngredientButton_clicked();
    sEditor = new StepsEditor();
    connect(this,SIGNAL(stepsEditButton_clicked(int)),sEditor,SLOT(setSteps(int)));
    oldName = "";
    setProperty("window",true);
}

RecipeEditor::~RecipeEditor()
{
    delete ui;
}

void RecipeEditor::setRecipe(QString str)
{
    while(buttons.size() > 0){
        QHBoxLayout *item = (QHBoxLayout*)ui->ingredientsList->takeAt(0);
        QLayoutItem* child;
        while((child = item->takeAt(0)) != nullptr){
            delete child->widget();
            delete child;
        }
        delete item;
        buttons.removeAt(0);
    }
    if(!str.isEmpty()){
        QStringList list = str.split("|");
        QString header = list[0];
        QString name = header.split("&").at(0);
        QString desc = header.split("&").at(1);
        QString photo = header.split("&").at(2);
        oldPhoto = photo;
        if(photo.isEmpty()){
            photo = ":/ico/ico/camera.png";
            ui->photoLabel->setScaledContents(false);
        }
        else{
            photo = "img/" + photo;
            ui->photoLabel->setScaledContents(true);
        }
        oldName = name;
        ui->recipeNameEdit->setText(name);
        ui->descriptionEdit->setPlainText(desc);
        ui->photoLabel->setPixmap(QPixmap::fromImage(QImage(photo)));
        for(int i = 1; i < list.size(); i++){
            QString ingredient = list[i];
            QString i_name = ingredient.split("&").at(0);
            QString quantity = ingredient.split("&").at(1);
            addIngredient(i_name, quantity);
        }
    }
    else{
        ui->recipeNameEdit->clear();
        ui->descriptionEdit->clear();
        oldName.clear();
        oldPhoto.clear();
        ui->photoLabel->clear();
        addIngredient();
    }
}

void RecipeEditor::on_addIngredientButton_clicked()
{
    addIngredient();
}

void RecipeEditor::enableSaveButton()
{
    ui->stepsEditButton->setEnabled(!ui->recipeNameEdit->text().isEmpty() && !ui->recipeNameEdit->text().isNull());
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

bool photoExists(QString name){
    QSqlQuery query;
    bool ok = query.prepare("SELECT id FROM photos WHERE photo = :name");
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
        qDebug()<<"Prepare get id"<<query.lastError();
    }
    query.bindValue(":value",value);
    ok = query.exec();
    if(!ok){
        qDebug()<<"Exec get id"<<query.lastError();
    }
    query.next();
    int id = query.value(0).toInt(&ok);
    if(!ok){
        qDebug()<<"Value get id"<<query.lastError();
    }
    return id;
}

void deleteFrom(QString table, QString column, QString value){
    QSqlQuery query;
    QString str = "DELETE FROM " + table + " WHERE " + column + " = :value";
    bool ok = query.prepare(str);
    if(!ok){
        qDebug()<<"Prepare delete from"<<query.lastError();
    }
    query.bindValue(":value",value);
    ok = query.exec();
    if(!ok){
        qDebug()<<"Exec delete from"<<query.lastError();
    }
}

QString addIdToPhoto(QString photo, int id){
    QString name = photo.split(".").at(0);
    QString ext = photo.split(".").at(1);
    name = name + "_" + QString::number(id);
    QString retval = name + "." + ext;
    return retval;
}

void RecipeEditor::on_saveButton_clicked()
{
    QString recipeName = ui->recipeNameEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    QString photo = ui->photoLabel->filename;
    saveName(recipeName, description);
    int recipe_id = getId("recipes","name",recipeName);
    savePhoto(photo, recipe_id);
    deleteFrom("recipe_to_ingredient","recipe_id",QString::number(recipe_id));
    for(int i=0;i<ui->ingredientsList->count();i++){
        QHBoxLayout *ingredient = (QHBoxLayout*)ui->ingredientsList->itemAt(i);
        QLineEdit *nameEdit = (QLineEdit*)ingredient->itemAt(0)->widget();
        QString name = nameEdit->text();
        QLineEdit *quantityEdit = (QLineEdit*)ingredient->itemAt(1)->widget();
        QString quantity = quantityEdit->text();
        saveIngredient(name, quantity, recipe_id);
    }
    refreshCompleter();
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
    on_saveButton_clicked();
    int recipe_id = getId("recipes","name",oldName);
    emit stepsEditButton_clicked(recipe_id);
}

void RecipeEditor::addIngredient(QString name, QString quantity)
{
    QHBoxLayout *item = new QHBoxLayout();
    QLineEdit *nameEdit = new QLineEdit();
    nameEdit->setPlaceholderText("Название");
    nameEdit->setText(name);
    nameEdit->setCompleter(completer);
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

void RecipeEditor::saveName(QString name, QString description)
{
    QSqlQuery query;
    bool ok;
    if(oldName.isEmpty()){
        ok = query.prepare("INSERT INTO recipes (name, description, name_lower)"
                             "VALUES (?,?,?);");
        if(!ok){
            qDebug()<<"Is empty prepare"<<query.lastError();
        }
        query.bindValue(0,name);
        query.bindValue(1,description);
        query.bindValue(2,name.toLower());
        ok = query.exec();
        if(!ok){
            qDebug()<<"is empty exec"<<query.lastError();
        }
    }
    else{
        ok = query.prepare("UPDATE recipes "
                                "SET name = :name, description = :desc, name_lower = :name_l "
                                "WHERE name = :old_name");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(":name",name);
        query.bindValue(":desc",description);
        query.bindValue(":name_l",name.toLower());
        query.bindValue(":old_name",oldName);
        ok = query.exec();
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    oldName = name;
}

void RecipeEditor::savePhoto(QString photo, int recipe_id)
{
    QSqlQuery query;
    bool ok;
    if(!photo.isEmpty()){
        QImage image(ui->photoLabel->path);
        photo = addIdToPhoto(photo,recipe_id);
        if(oldPhoto.isEmpty()){
            ok = query.prepare("INSERT INTO photos (photo, recipe_id) "
                               "VALUES (:name, :id)");
            if(!ok){
                qDebug()<<query.lastError();
            }
            query.bindValue(":name",photo);
            query.bindValue(":id",recipe_id);
            ok = query.exec();
            if(!ok){
                qDebug()<<query.lastError();
            }
        }
        else{
            ok = query.prepare("UPDATE photos "
                                    "SET photo = :name, recipe_id = :id "
                                    "WHERE photo = :old_name");
            if(!ok){
                qDebug()<<query.lastError();
            }
            query.bindValue(":name",photo);
            query.bindValue(":id",recipe_id);
            query.bindValue(":old_name",oldPhoto);
            ok = query.exec();
            if(!ok){
                qDebug()<<query.lastError();
            }
            QFile::remove("img/" + oldPhoto);
        }
        QString url = "img/" + photo;
        image.save(url);
    }
    oldPhoto = photo;
}

void RecipeEditor::saveIngredient(QString name, QString quantity, int recipe_id)
{
    QSqlQuery query;
    bool ok;
    if(!ingredientExists(name)){
        ok = query.prepare("INSERT INTO ingredients (name, name_lower)"
                      "VALUES (:name, :name_lower);");
        if(!ok){
            qDebug()<<"ingredient prepare"<<query.lastError();
        }
        query.bindValue(":name",name);
        query.bindValue(":name_lower",name.toLower());
        ok = query.exec();
        if(!ok){
            qDebug()<<"ingredient exec"<<query.lastError();
        }
    }
    int ingredient_id = getId("ingredients","name",name);
    ok = query.prepare("INSERT INTO recipe_to_ingredient (recipe_id, ingredient_id, quantity)"
                  "VALUES (:rid, :iid, :quantity);");
    if(!ok){
        qDebug()<<"rtoi prepare"<<query.lastError();
    }
    query.bindValue(":rid",recipe_id);
    query.bindValue(":iid",ingredient_id);
    query.bindValue(":quantity",quantity);
    ok = query.exec();
    if(!ok){
        qDebug()<<"rtoi exec"<<query.lastError();
    }
}

void RecipeEditor::refreshCompleter()
{
    delete completer;
    QStringList ingredients = getIngredients();
    completer = new QCompleter(ingredients,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
}

QStringList RecipeEditor::getIngredients()
{
    QSqlQuery query;
    bool ok = query.exec("SELECT name FROM ingredients");
    if(!ok){
        qDebug()<<query.lastError();
    }
    QStringList result;
    while(query.next()){
        QString name = query.value(0).toString();
        result << name;
    }
    return result;
}
