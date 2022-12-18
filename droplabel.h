#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QObject>
#include <QLabel>
#include <QtWidgets>

class DropLabel : public QLabel
{
    Q_OBJECT

protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);

public:
    DropLabel(QWidget *pwgt = 0);
    QString path;
    QString filename;
    void clear();
};

#endif // DROPLABEL_H
