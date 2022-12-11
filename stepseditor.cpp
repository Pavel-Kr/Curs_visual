#include "stepseditor.h"
#include "ui_stepseditor.h"
#include <QLabel>
#include <QLineEdit>
#include <QtSql>

StepsEditor::StepsEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepsEditor)
{
    ui->setupUi(this);
    addStep();
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

void StepsEditor::addStep(QString desc)
{
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *photo = new QLabel();
    photo->setText("Фото шага");
    QSize size;
    size.setWidth(150);
    size.setHeight(150);
    photo->setMinimumSize(size);
    photo->setMaximumSize(size);
    photo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    photo->setFrameShape(QFrame::Panel);
    QLineEdit *stepEdit = new QLineEdit();
    stepEdit->setPlaceholderText("Описание шага");
    stepEdit->setText(desc);
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
    for(int i=0;i<ui->stepList->count();i++){
        QHBoxLayout *layout = (QHBoxLayout*)ui->stepList->itemAt(i);
        QLineEdit *descEdit = (QLineEdit*)layout->itemAt(1)->widget();
        QString desc = descEdit->text();
        bool ok = query.prepare("INSERT INTO steps (description, number, recipe_id)"
                                "VALUES (:desc, :num, :id);");
        if(!ok){
            qDebug()<<query.lastError();
        }
        query.bindValue(":desc",desc);
        query.bindValue(":num",i+1);
        query.bindValue(":id",recipe_id);
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
    bool ok = query.prepare("SELECT description FROM steps WHERE recipe_id = :id");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    while(query.next()){
        addStep(query.value(0).toString());
    }
    if(ui->stepList->count() == 0){
        addStep();
    }
}
