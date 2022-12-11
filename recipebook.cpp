#include "recipebook.h"
#include "ui_recipebook.h"
#include <QDebug>
#include <QMessageBox>
#include <QListWidget>
#include <QFile>
#include <QString>

RecipeBook::RecipeBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RecipeBook)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Recipes.db");
    bool need_setup = !QFile::exists("Recipes.db");
    qDebug()<<need_setup;
    if(!db.open()){
        qDebug()<<db.lastError();
        QMessageBox::critical(this,"Ошибка","Не удалось подключиться к базе данных!",QMessageBox::Ok);
        this->close();
    }
    else{
        qDebug()<<"Success!";
    }
    if(need_setup){
        qDebug()<<"Creating database...";
        createDatabase();
    }
    connect(ui->searchBar,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));
    ui->searchByNameRB->setChecked(true);
    this->search("");
    editor = new RecipeEditor();
    viewer = new RecipeViewer();
    connect(this,SIGNAL(send_to_viewer(QString)),viewer,SLOT(setRecipe(QString)));
    connect(viewer,SIGNAL(recipeChanged()),this,SLOT(updateList()));
    connect(editor,SIGNAL(recipeChanged()),this,SLOT(updateList()));
}

RecipeBook::~RecipeBook()
{
    delete ui;
    db.close();
    QSqlDatabase::removeDatabase("Recipes");
    delete editor;
    delete viewer;
}

void RecipeBook::search(QString str)
{
    QSqlQuery query;
    QListWidgetItem *item;
    while((item = ui->recipeList->takeItem(0)) != nullptr){
        delete item;
    }
    QString s = str.toLower();
    if(ui->searchByNameRB->isChecked()){
        bool ok = query.exec("SELECT name, description FROM recipes WHERE name_lower LIKE '%" + s + "%'");
        if(!ok){
            qDebug()<<query.lastError();
        }
        while (query.next()) {
            QString name = query.value(0).toString();
            QString desc = query.value(1).toString();
            QListWidgetItem *item = new QListWidgetItem();

            item->setText(name + "\n\n" + desc.left(100) + "...");
            ui->recipeList->addItem(item);
        }
    }
    else if(ui->searchByIngredientRB->isChecked()){
        bool ok = query.exec("SELECT DISTINCT recipes.name, recipes.description FROM ingredients "
                                "JOIN recipe_to_ingredient ON recipe_to_ingredient.ingredient_id = ingredients.id AND ingredients.name_lower LIKE '" + s + "%' "
                                "JOIN recipes ON recipe_to_ingredient.recipe_id = recipes.id");
        if(!ok){
            qDebug()<<query.lastError();
        }
        while (query.next()) {
            QString name = query.value(0).toString();
            QString desc = query.value(1).toString();
            QListWidgetItem *item = new QListWidgetItem();
            item->setText(name + "\n\n" + desc.left(100) + "...");
            ui->recipeList->addItem(item);
        }
    }
}

void createDatabase(){
    QSqlQuery query;
    bool ok = query.exec("CREATE TABLE recipes("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT NOT NULL,"
               "name_lower TEXT NOT NULL,"
               "description TEXT"
               ");");
    if(!ok){
        qDebug()<<query.lastError();
    }
    ok = query.exec("CREATE TABLE ingredients("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "name TEXT NOT NULL,"
                    "name_lower NOT NULL"
                    ");");
    if(!ok){
        qDebug()<<query.lastError();
    }
    ok = query.exec("CREATE TABLE steps("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "description TEXT NOT NULL,"
                    "photo BLOB,"
                    "number INTEGER,"
                    "recipe_id INTEGER,"
                    "FOREIGN KEY (recipe_id) REFERENCES recipes (id)"
                    ");");
    if(!ok){
        qDebug()<<query.lastError();
    }
    ok = query.exec("CREATE TABLE photos("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "photo BLOB NOT NULL,"
                    "recipe_id INTEGER,"
                    "FOREIGN KEY (recipe_id) REFERENCES recipes (id)"
                    ");");
    if(!ok){
        qDebug()<<"photos"<<query.lastError();
    }
    ok = query.exec("CREATE TABLE recipe_to_ingredient("
                    "recipe_id INTEGER,"
                    "ingredient_id INTEGER,"
                    "quantity INTEGER,"
                    "FOREIGN KEY (recipe_id) REFERENCES recipes (id),"
                    "FOREIGN KEY (ingredient_id) REFERENCES ingredients (id)"
                    ");");
    if(!ok){
        qDebug()<<"rtoi"<<query.lastError();
    }
}

void RecipeBook::on_addRecipeButton_clicked()
{
    editor->show();
}

void RecipeBook::on_recipeList_itemClicked(QListWidgetItem *item)
{
    QString str;
    QSqlQuery query;
    QStringList strSplit = item->text().split("\n");
    QString name = strSplit[0];
    bool ok = query.prepare("SELECT description FROM recipes WHERE name = :name");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":name",name);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.next();
    QString desc = query.value(0).toString();
    str += name + "&" + desc;
    ok = query.prepare("SELECT ingredients.name, recipe_to_ingredient.quantity FROM recipes "
                            "JOIN recipe_to_ingredient ON recipes.id = recipe_to_ingredient.recipe_id AND recipes.name = :name "
                            "JOIN ingredients ON ingredients.id = recipe_to_ingredient.ingredient_id;");
    if(!ok){
        qDebug()<<"Prepare"<<query.lastError();
    }
    query.bindValue(":name",name);
    ok = query.exec();
    if(!ok){
        qDebug()<<"Exec"<<query.lastError();
    }
    while(query.next()){
        QString ingredient = query.value(0).toString();
        QString quantity = query.value(1).toString();
        str += "|" + ingredient + "&" + quantity;
    }
    viewer->show();
    emit send_to_viewer(str);

}

void RecipeBook::updateList()
{
    search(ui->searchBar->text());
}
