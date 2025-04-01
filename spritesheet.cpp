/**
 * @Authors: ....
 *
 * The implementation of the spritesheet class
 */

#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>
#include "spritesheet.h"
#include <iostream>

/**
 * Constructs the a QObject and current status of a palette
 * @param parent - pointer to a parent QObject
 */
Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}, currentFrame(0), palette(this)
{
    QObject::connect(&timeline, &Timeline::goToNextSprite, this, &Spritesheet::goToNextSprite);
}

/**
 * This method saves the current sprite to a JSON for the user
 * @param filePath - the current file path where the user wants to save
 * @return - true if file was able to be saved, false otherwise
 */
void Spritesheet::saveToJson(QString &filePath)
{
    QJsonDocument jsonDoc(toJson());
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file(filePath);

    // Check if file was able to be saved
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(jsonData);
        file.close();
    }
}

/**
 * This method loads a sprite from a JSON to the current sprite sheet
 * @param filePath - the current file path the user is using to load sprite
 * @return - true if the file was able to be loaded, false otherwise
 */
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

/**
 * This method creates a new instance of a frame/sprite for the user to work on
 * @param newWidth - the new width value
 * @param newHeight - the new height value
 */
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

/**
 * This method returns the current sprite from the spritesheet
 * @return - the current sprite
 */
Sprite &Spritesheet::getCurrentSprite()
{
    return sprites[currentFrame];
}

/**
 * This method gets the current coordinates of where the
 * current sprite is being painted
 * @param x - the x coordinate
 * @param y - the y coordinate
 */
void Spritesheet::paintedCurrentSpriteAt(int x, int y)
{
    int brushRadius = palette.getBrush()->getRadius();
    getCurrentSprite().paintAt(x, y, brushRadius, palette.getCurrentColor());
}

/**
 * This method gets the current coordinates of where the current
 * sprite is erased
 * @param x - the x coordinate
 * @param y - the y coordinate
 */
void Spritesheet::erasedCurrentSpriteAt(int x, int y)
{
    int brushRadius = palette.getBrush()->getRadius();
    getCurrentSprite().eraseAt(x, y, brushRadius);
}

/**
 * This method returns the current palette
 * @return - the current palette
 */
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
    if (sprites.size() <= 1)
        return;

    currentFrame++;

    if (currentFrame >= sprites.size())
    {
        currentFrame = 0;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
    emitIfNextOrPreviousSprites();
}

void Spritesheet::goToPreviousSprite()
{
    if (sprites.size() <= 1)
        return;

    currentFrame--;

    if (currentFrame < 0)
    {
        currentFrame = sprites.size() - 1;
    }

    emit currentSpriteUpdated(&sprites[currentFrame]);
    emit currentSpriteID(currentFrame);
    emitIfNextOrPreviousSprites();
}

void Spritesheet::addSprite()
{
    sprites.push_back(Sprite(width, height));

    currentFrame = sprites.size() - 1;

    if (sprites.size() == 2)
    {
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
