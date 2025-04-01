#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>
#include <iostream>
#include "spritesheet.h"

Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}, palette(this)
{
}

void Spritesheet::saveToJson(QString& filePath) {

    QJsonDocument jsonDoc(toJson());
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonData);
        file.close();
    }
}

void Spritesheet::loadJson(QString& filePath) {

    //Check the file at the specified path
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        abort();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    //Check if the format of the file is correct
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        abort();
    }

    QJsonObject jsonObj = jsonDoc.object();

    //Extract sprite sheet details
    projectName = jsonObj["projectName"].toString().toStdString();
    width = jsonObj["width"].toInt();
    height = jsonObj["height"].toInt();

    //Clear current sprite sheet!
    sprites.clear();
    currentFrame = 0;

    //Extract sprite data
    QJsonArray spriteArray = jsonObj["sprites"].toArray();

    //Reconstruct each sprite and put it into sprite vector
    for (const QJsonValue& spriteValue : spriteArray) {
        if (!spriteValue.isObject()) continue;
        QJsonObject spriteObj = spriteValue.toObject();

        Sprite sprite;
        sprite.fromJson(spriteObj);
        sprite.setSize(width, height);
        sprites.push_back(sprite);
    }

    emit updateSpriteSizeUI(width, height);
}

void Spritesheet::newProject(int newWidth, int newHeight)
{
    sprites.clear();

    width = newWidth;
    height = newHeight;

    Sprite* newSprite = new Sprite(newWidth, newHeight);

    //will be changed to following
    sprites.push_back(*newSprite); //timeline.addSprite();

    currentFrame = 0;

    // emits the new sprite
    emit currentSpriteUpdated(&sprites[currentFrame]);
}

Sprite& Spritesheet::getCurrentSprite() {
    return sprites[currentFrame];
}

void Spritesheet::paintedCurrentSpriteAt(int x, int y)
{
    int brushRadius = palette.getBrush()->getRadius();
    getCurrentSprite().paintAt(x, y, brushRadius, palette.getCurrentColor());
}

void Spritesheet::erasedCurrentSpriteAt(int x, int y)
{
    int brushRadius = palette.getBrush()->getRadius();
    getCurrentSprite().eraseAt(x, y, brushRadius);
}


 Palette& Spritesheet::getPalette()
{
    return palette;
}
