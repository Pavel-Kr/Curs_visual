#include "recipebook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RecipeBook w;
    w.show();

    return a.exec();
}
