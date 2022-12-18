#include "stepsviewer.h"
#include "ui_stepsviewer.h"
#include <QtSql>
#include <QDebug>

StepsViewer::StepsViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepsViewer)
{
    ui->setupUi(this);
    setProperty("window",true);
}

StepsViewer::~StepsViewer()
{
    delete ui;
}

void StepsViewer::setRecipe(int recipe_id)
{
    QSqlQuery query;
    bool ok = query.prepare("SELECT description, number, photo FROM steps WHERE recipe_id = :id ORDER BY number");
    if(!ok){
        qDebug()<<query.lastError();
    }
    query.bindValue(":id",recipe_id);
    ok = query.exec();
    if(!ok){
        qDebug()<<query.lastError();
    }
    descriptions.clear();
    numbers.clear();
    photos.clear();
    while (query.next()) {
        QString desc = query.value(0).toString();
        QString number = query.value(1).toString();
        QString photo = query.value(2).toString();
        descriptions.push_back(desc);
        numbers.push_back(number);
        photos.push_back(photo);
    }
    if(descriptions.size() > 0 && numbers.size() > 0 && photos.size() > 0){
        ui->numberLabel->setText(numbers[0]);
        ui->descLabel->setText(descriptions[0]);
        index = 0;
        ui->prevButton->setEnabled(false);
        ui->nextButton->setText("Следующий шаг");
        setPhoto();
    }
    else{
        ui->prevButton->setEnabled(false);
        ui->nextButton->setEnabled(false);
        ui->nextButton->setText("Закончить приготовление");
        ui->numberLabel->setText("0");
        ui->descLabel->setText("Ошибка: нет шага");
    }
}

void StepsViewer::on_nextButton_clicked()
{
    index++;
    if(index == numbers.size()){
        close();
        return;
    }
    ui->numberLabel->setText(numbers[index]);
    ui->descLabel->setText(descriptions[index]);
    setPhoto();
    if(index + 1 == numbers.size()){
        ui->nextButton->setText("Закончить приготовление");
    }
    if(index > 0){
        ui->prevButton->setEnabled(true);
    }
}

void StepsViewer::on_prevButton_clicked()
{
    index--;
    ui->numberLabel->setText(numbers[index]);
    ui->descLabel->setText(descriptions[index]);
    setPhoto();
    if(index == 0){
        ui->prevButton->setEnabled(false);
    }
    if(index + 1 < numbers.size()){
        ui->nextButton->setText("Следующий шаг");
    }
}

void StepsViewer::setPhoto()
{
    QString photo = photos[index];
    if(!photo.isEmpty()){
        ui->photoLabel->setPixmap(QPixmap::fromImage(QImage("img/" + photo)));
        ui->photoLabel->setScaledContents(true);
    }
    else{
        ui->photoLabel->setPixmap(QPixmap::fromImage(QImage(":/ico/ico/camera.png")));
        ui->photoLabel->setScaledContents(false);
    }
}
