#ifndef REQUESTHADLER_H
#define REQUESTHADLER_H
#include <Item.h>
#include <QByteArray>
#include <QString>
#include <QVector>
#include <QStringList>
#include <QJsonArray>

class RequestManager {
public:
    RequestManager();
    QString getToken(QByteArray array);
    QVector<Item> getItems(QByteArray array);
    QStringList getFileList(QByteArray array);
    int getNumProcessors(QByteArray array);
private:
    Item fromQJsonArray(QJsonArray array, int index);

};

#endif // REQUESTHADLER_H
