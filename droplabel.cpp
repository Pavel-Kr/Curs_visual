#include "droplabel.h"
#include <QMessageBox>

void DropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
    }
}

void DropLabel::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    QString str = urls[0].toString();
    QString url = str.split("///")[1];
    qDebug()<<url;
    path = url;
    filename = url.split("/").last();
    if(QFile::exists("img/" + filename)){
        QMessageBox::warning(this,"Внимание!","Это фото уже относится к другому рецепту, пожалуйста выберите другое фото!",QMessageBox::Ok);
    }
    else{
        QImage image;
        bool ok = image.load(url);
        if(!ok){
            qDebug()<<"load error";
        }
        else{
            qDebug()<<"load success";
        }

        qDebug()<<filename;
        setScaledContents(true);
        setPixmap(QPixmap::fromImage(image));
    }
}

DropLabel::DropLabel(QWidget *pwgt) : QLabel(pwgt)
{
    setAcceptDrops(true);
}

void DropLabel::clear()
{
    setScaledContents(false);
    setPixmap(QPixmap::fromImage(QImage(":/ico/ico/camera.png")));
    filename.clear();
}
