#include "recipebook.h"
#include <QApplication>
#include <QDir>
#include <QtWidgets>

void loadModules(){
    QTime time;
    time.start();
    for(int i=0;i<100;){
        if(time.elapsed()>20){
            time.start();
            ++i;
        }
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir dir;
    if(!dir.exists("img")){
        dir.mkdir("img");
    }
    QFile styleF(":/style/style.qss");
    styleF.open(QFile::ReadOnly);
    QString style = styleF.readAll();
    a.setStyleSheet(style);
    QSplashScreen screen(QPixmap(":/ico/ico/load screen.png"));
    screen.show();
    RecipeBook w;
    loadModules();
    screen.finish(&w);
    w.show();
    return a.exec();
}
