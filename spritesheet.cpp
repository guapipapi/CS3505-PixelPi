/**
 * @Authors: ....
 *
 * The implementation of the spritesheet class
 */

#include <QCoreApplication>
#include <QJsonDocument>
#include <QFile>
#include "spritesheet.h"

/**
 * Constructs the a QObject and current status of a palette
 * @param parent - pointer to a parent QObject
 */
Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}, palette(this)
{
}

/**
 * This method saves the current sprite to a JSON for the user
 * @param filePath - the current file path where the user wants to save
 * @return - true if file was able to be saved, false otherwise
 */
bool Spritesheet::saveToJson(QString& filePath) {
    QJsonDocument jsonDoc(toJson());
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    //Add actual filename to the path
    filePath += (projectName + ".spf");

    QFile file(filePath);

    // Check if file was able to be saved
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonData);
        file.close();

        return true;
    }

    return false;
}

/**
 * This method loads a sprite from a JSON to the current sprite sheet
 * @param filePath - the current file path the user is using to load sprite
 * @return - true if the file was able to be loaded, false otherwise
 */
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

/**
 * This method creates a new instance of a frame/sprite for the user to work on
 * @param newWidth - the new width value
 * @param newHeight - the new height value
 */
void Spritesheet::newProject(int newWidth, int newHeight)
{
    sprites.clear();

    // Create whole new sprite
    Sprite* newSprite = new Sprite(newWidth, newHeight);

    sprites.push_back(*newSprite);

    currentFrame = 0;

    // emits the new sprite
    emit currentSpriteUpdated(&sprites[currentFrame]);
}

/**
 * This method returns the current sprite from the spritesheet
 * @return - the current sprite
 */
Sprite& Spritesheet::getCurrentSprite() {
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
 Palette& Spritesheet::getPalette()
{
    return palette;
}
// - Checked by
