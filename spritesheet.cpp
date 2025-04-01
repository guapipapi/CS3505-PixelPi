#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>
#include <iostream>
#include "spritesheet.h"

Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}, currentFrame(0), palette(this)
{
    QObject::connect(&timeline, &Timeline::goToNextSprite, this, &Spritesheet::goToNextSprite);
}

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

    width = newWidth;
    height = newHeight;

    addSprite();

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

Timeline& Spritesheet::getTimeline(){
    return timeline;
}

void Spritesheet::goToNextSprite(){
    int max = sprites.size();
    if(currentFrame < max-1){
        currentFrame++;
    }
    else
    {
        currentFrame = 0;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
}

void Spritesheet::addSprite(){
    // Add new sprite at the beginning
    sprites.push_back(Sprite(width, height));

    currentFrame = sprites.size()-1;

    emit currentSpriteID(currentFrame);
    emit currentSpriteUpdated(&sprites[currentFrame]);
}

void Spritesheet::removeSprite(){
    sprites.pop_back();

    if(sprites.size() < 1)
        addSprite();

    if (currentFrame >= int(sprites.size()))
    {
        currentFrame = sprites.size()-1;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
}
