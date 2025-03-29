#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>

#include "spritesheet.h"

Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}
{}

bool Spritesheet::saveToJson(QString& filePath) {

    QJsonDocument jsonDoc(toJson());
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    //Add actual filename to the path
    filePath += (projectName + ".spf");

    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonData);
        file.close();

        return true;
    }

    return false;
}

bool Spritesheet::loadJson(QString& filePath) {

    //Check the file at the specified path
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    //Check if the format of the file is correct
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        return false;
    }

    QJsonObject jsonObj = jsonDoc.object();

    //Extract sprite sheet details
    projectName = jsonObj["projectName"].toString().toStdString();
    width = jsonObj["width"].toInt();
    height = jsonObj["height"].toInt();
    currentFrame = jsonObj["currentFrame"].toInt();

    //Extract sprite data
    sprites.clear();
    QJsonArray spriteArray = jsonObj["sprites"].toArray();

    //Reconstruct each sprite and put it into sprite vector
    for (const QJsonValue& spriteValue : spriteArray) {
        if (!spriteValue.isObject()) continue;
        QJsonObject spriteObj = spriteValue.toObject();

        Sprite sprite;
        sprite.fromJson(spriteObj);
        sprites.push_back(sprite);
    }

    return true;
}

void Spritesheet::newProject(int newWidth, int newHeight)
{
    sprites.clear();

    Sprite* newSprite = new Sprite(newWidth, newHeight);


    //will be changed to following
    sprites.push_back(*newSprite); //timeline.addSprite();

    currentFrame = 0;
}

bool Spritesheet::exportToPNG() {

    //PNG library needed here l0l

    return false;
}

Sprite& Spritesheet::getCurrentSprite() {
    return sprites[currentFrame];
}
