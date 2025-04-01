#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>
#include "spritesheet.h"
#include <iostream>

Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}, currentFrame(0), palette(this)
{
    QObject::connect(&timeline, &Timeline::goToNextSprite, this, &Spritesheet::goToNextSprite);
}

void Spritesheet::saveToJson(QString &filePath)
{

    QJsonDocument jsonDoc(toJson());
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(jsonData);
        file.close();
    }
}

void Spritesheet::loadJson(QString &filePath)
{

    // Check the file at the specified path
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        abort();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    // Check if the format of the file is correct
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        abort();
    }

    QJsonObject jsonObj = jsonDoc.object();

    // Extract sprite sheet details
    projectName = jsonObj["projectName"].toString().toStdString();
    width = jsonObj["width"].toInt();
    height = jsonObj["height"].toInt();

    // Clear current sprite sheet!
    sprites.clear();
    currentFrame = 0;

    // Extract sprite data
    QJsonArray spriteArray = jsonObj["sprites"].toArray();

    // Reconstruct each sprite and put it into sprite vector
    for (const QJsonValue &spriteValue : spriteArray)
    {
        if (!spriteValue.isObject())
            continue;
        QJsonObject spriteObj = spriteValue.toObject();

        Sprite sprite;
        sprite.fromJson(spriteObj);
        sprite.setSize(width, height);
        sprites.push_back(sprite);
    }

    emit updateSpriteSizeUI(width, height);

    emitIfNextOrPreviousSprites();
}

void Spritesheet::newProject(int newWidth, int newHeight)
{
    sprites.clear();

    width = newWidth;
    height = newHeight;

    addSprite();

    currentFrame = 0;

    emit canPlayAnimation(false);

    // emits the new sprite
    emit currentSpriteUpdated(&sprites[currentFrame]);

    emitIfNextOrPreviousSprites();
}

Sprite &Spritesheet::getCurrentSprite()
{
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

Palette &Spritesheet::getPalette()
{
    return palette;
}

Timeline &Spritesheet::getTimeline()
{
    return timeline;
}

void Spritesheet::goToNextSprite()
{
    if (sprites.size() <= 1) return;

    currentFrame++;

    if (currentFrame >= sprites.size()) {
        currentFrame = 0;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
    emitIfNextOrPreviousSprites();
}

void Spritesheet::goToPreviousSprite()
{
    if (sprites.size() <= 1) return;

    currentFrame--;

    if (currentFrame < 0) {
        currentFrame = sprites.size() - 1;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
    emitIfNextOrPreviousSprites();
}

void Spritesheet::addSprite()
{
    sprites.push_back(Sprite(width, height));

    currentFrame = sprites.size()-1;

    if (sprites.size() == 2) {
        emit canPlayAnimation(true);
    }

    timeline.stopAnimation();
    emitIfNextOrPreviousSprites();
    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
}

void Spritesheet::removeSprite()
{
    sprites.erase(sprites.begin() + currentFrame);

    if (sprites.size() <= 1)
    {
        if (sprites.size() < 1)
        {
            addSprite();
        }

        emitIfNextOrPreviousSprites();
        emit canPlayAnimation(false);
    }


    if (currentFrame >= int(sprites.size()))
    {
        currentFrame = sprites.size() - 1;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
}

void Spritesheet::emitIfNextOrPreviousSprites()
{
    bool hasPrevious = (currentFrame > 0) && !sprites.empty();
    bool hasNext = (currentFrame < sprites.size() - 1) && !sprites.empty();

    emit isTherePreviousSprite(hasPrevious);
    emit isThereNextSprite(hasNext);
}
