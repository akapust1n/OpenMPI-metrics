#include "RequestManager.h"
#include <iostream>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>

RequestManager::RequestManager()
{

}

QString RequestManager::getToken(QByteArray array)
{
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QString response = itemObject["token"].toString();

    return  response;
    
}

QVector<Item> RequestManager::getItems(QByteArray array)
{
    QVector<Item> result;
    std::cout<<"PROCS "<<array.toStdString()<<std::endl;
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    for(int i=0;i<resultArray.size();i++){
          result.append(fromQJsonArray(resultArray,i));
    }
    return  result;
    
}

QStringList RequestManager::getFileList(QByteArray array)
{
    QStringList result;
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray fileArray = itemObject["message"].toArray();
    for(auto temp:fileArray){
      std::cout<<temp.toString().toStdString()<<std::endl;
      result.append(temp.toString());
    }
    return  result;

}

int RequestManager::getNumProcessors(QByteArray array)
{
    std::cout<<"PROCS "<<array.toStdString()<<std::endl;
    QJsonDocument document =  QJsonDocument::fromJson(array);
    QJsonObject itemObject = document.object();
    QJsonArray resultArray = itemObject["result"].toArray();
    QJsonObject temp1 = resultArray.at(0).toObject();
    int result = temp1["max(prid)"].toInt();

    return  result;
}

Item RequestManager::fromQJsonArray(QJsonArray array, int index)
{
    Item item;
    QJsonObject object = array.at(index).toObject();
    item.pid = object["pid"].toInt();
    item.prid = object["prid"].toInt();
    item.time= object["time"].toDouble();
    item.typeEvent= object["typeEvent"].toInt();
    item.typeRecord= object["typeEvent"].toInt();

    return  item;



}
