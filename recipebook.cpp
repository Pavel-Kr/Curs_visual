#include "recipebook.h"
#include "ui_recipebook.h"
#include "functions.h"
#include <QDebug>
#include <QMessageBox>
#include <QListWidget>
#include <QFile>
#include <QString>
#include <QImageReader>

RecipeBook::RecipeBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RecipeBook)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Recipes.db");
    bool need_setup = !QFile::exists("Recipes.db");
    if(!db.open()){
        qDebug()<<db.lastError();
        QMessageBox::critical(this,"Ошибка","Не удалось подключиться к базе данных!",QMessageBox::Ok);
        this->close();
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
    viewer->setEditor(editor);
    connect(this,SIGNAL(send_to_viewer(QString)),viewer,SLOT(setRecipe(QString)));
    connect(viewer,SIGNAL(recipeChanged()),this,SLOT(updateList()));
    connect(editor,SIGNAL(recipeChanged()),this,SLOT(updateList()));
    help = new Help(":/help/help", "index.html");
    help->resize(800,600);
    connect(ui->helpAction,SIGNAL(triggered()),help,SLOT(show()));

    connect(ui->searchByNameRB,SIGNAL(clicked()),this,SLOT(updateList()));
    connect(ui->searchByIngredientRB,SIGNAL(clicked()),this,SLOT(updateList()));

    setProperty("window",true);
}

RecipeBook::~RecipeBook()
{
    delete ui;
    db.close();
    QSqlDatabase::removeDatabase("Recipes");
    delete editor;
    delete viewer;
    delete help;
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
        bool ok = query.exec("SELECT recipes.name, recipes.description, photos.photo FROM recipes "
                             "LEFT JOIN photos ON recipes.id = photos.recipe_id WHERE recipes.name_lower LIKE '%" + s + "%' "
                             "ORDER BY recipes.name");
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    else if(ui->searchByIngredientRB->isChecked()){
        bool ok = query.exec("SELECT DISTINCT recipes.name, recipes.description, photos.photo FROM ingredients "
                                "JOIN recipe_to_ingredient ON recipe_to_ingredient.ingredient_id = ingredients.id AND ingredients.name_lower LIKE '%" + s + "%' "
                                "JOIN recipes ON recipe_to_ingredient.recipe_id = recipes.id "
                                "LEFT JOIN photos ON recipes.id = photos.recipe_id "
                                "ORDER BY recipes.name");
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    while (query.next()) {
        QString name = query.value(0).toString();
        QString desc = query.value(1).toString();
        QString photo = query.value(2).toString();
        QListWidgetItem *item = new QListWidgetItem();
        QString text = name + "\n\n" + desc;
        item->setText(text);
        if(photo.isEmpty()){
            item->setIcon(QIcon(QPixmap(":/ico/ico/camera.png").scaledToWidth(100)));
        }
        else {
            photo = "img/" + photo;
            item->setIcon(QIcon(QPixmap::fromImage(QImage(photo)).scaledToWidth(100)));
        }
        ui->recipeList->addItem(item);
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
                    "photo TEXT,"
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
    editor->setRecipe("");
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
    int recipe_id = getId("recipes","name",name);
    ok = query.prepare("SELECT photo FROM photos WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    QString photo = "";
    if(query.next()){
        photo = query.value(0).toString();
    }
    str += name + "&" + desc + "&" + photo;
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
    this->show();
    search(ui->searchBar->text());
}
