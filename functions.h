#ifndef DB_FUNCTIONS_H
#define DB_FUNCTIONS_H

int getId(QString table, QString column, QString value);
void deleteFrom(QString table, QString column, QString value);
QString addIdToPhoto(QString photo, int id);

#endif // DB_FUNCTIONS_H
