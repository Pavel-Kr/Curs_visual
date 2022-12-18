#include "stepseditor.h"
#include "ui_stepseditor.h"
#include "functions.h"
#include "droplabel.h"
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QtSql>

StepsEditor::StepsEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepsEditor)
{
    ui->setupUi(this);
    addStep();
    setProperty("window",true);
}

StepsEditor::~StepsEditor()
{
    delete ui;
}

void StepsEditor::on_addStepButton_clicked()
{
    addStep();
}

void StepsEditor::deleteStepSlot()
{
    QPushButton *senderButton = (QPushButton*)sender();
    for(int i=0;i<buttons.size();i++){
        if(buttons[i] == senderButton){
            deleteStepAt(i);
            break;
        }
    }
}

void StepsEditor::addStep(QString desc, QString photoPath)
{
    QHBoxLayout *layout = new QHBoxLayout();
    DropLabel *photo = new DropLabel();
    if(!photoPath.isEmpty()){
        photo->setPixmap(QPixmap("img/" + photoPath));
    }
    else{
        photo->setPixmap(QPixmap(":/ico/ico/camera.png"));
    }

    QSize size;
    size.setWidth(150);
    size.setHeight(125);
    photo->setMinimumSize(size);
    photo->setMaximumSize(size);
    photo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    photo->setFrameShape(QFrame::Panel);
    photo->setObjectName("photoLabel");
    QPlainTextEdit *stepEdit = new QPlainTextEdit();
    stepEdit->setPlaceholderText("Описание шага");
    stepEdit->setPlainText(desc);
    QPushButton *deleteButton = new QPushButton();
    deleteButton->setText("Удалить");
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteStepSlot()));
    layout->addWidget(photo);
    layout->addWidget(stepEdit);
    layout->addWidget(deleteButton);
    ui->stepList->addLayout(layout);
    buttons.push_back(deleteButton);
}

void StepsEditor::deleteStepAt(int index)
{
    QHBoxLayout *item = (QHBoxLayout*)ui->stepList->takeAt(index);
    QLayoutItem *child;
    while((child = item->takeAt(0)) != nullptr){
        delete child->widget();
        delete child;
    }
    delete item;
    buttons.removeAt(index);
}

void StepsEditor::on_saveButton_clicked()
{
    QSqlQuery query;
    deleteFrom("steps","recipe_id",QString::number(recipe_id));
    for(int i=0;i<ui->stepList->count();i++){
        QHBoxLayout *layout = (QHBoxLayout*)ui->stepList->itemAt(i);
        DropLabel *photoLabel = (DropLabel*)layout->itemAt(0)->widget();
        QString photo = photoLabel->filename;
        if(!photo.isEmpty()){
            photo = addIdToPhoto(photo,recipe_id);
            QImage image(photoLabel->path);
            image.save("img/" + photo);
        }
        QPlainTextEdit *descEdit = (QPlainTextEdit*)layout->itemAt(1)->widget();
        QString desc = descEdit->toPlainText();
        bool ok = query.prepare("INSERT INTO steps (description, number, recipe_id, photo)"
                                "VALUES (:desc, :num, :id, :photo);");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(":desc",desc);
        query.bindValue(":num",i+1);
        query.bindValue(":id",recipe_id);
        query.bindValue(":photo",photo);
        ok = query.exec();
        if(!ok){
            qDebug()<<query.lastError();
        }
    }
    close();
}

void StepsEditor::setSteps(int recipe_id)
{
    while(ui->stepList->count() > 0){
        deleteStepAt(0);
    }
    this->recipe_id = recipe_id;
    QSqlQuery query;
    bool ok = query.prepare("SELECT description, photo FROM steps WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    while(query.next()){
        addStep(query.value(0).toString(),query.value(1).toString());
    }
    if(ui->stepList->count() == 0){
        addStep();
    }
}
