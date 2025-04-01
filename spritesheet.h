#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QObject>
#include <vector>
#include <string>
#include <timeline.h>
#include <sprite.h>
#include <QJsonArray>
#include <palette.h>

class Spritesheet : public QObject
{
    Q_OBJECT
public:
    explicit Spritesheet(QObject *parent = nullptr);

    // Returns the current sprite
    Sprite &getCurrentSprite();

    // Creates a new project
    void newProject(int newWidth, int newHeight);

    Palette &getPalette();

    Timeline &getTimeline();

    // Convert sprite sheet to JSON
    QJsonObject toJson() const
    {
        QJsonObject jsonObj;

        jsonObj["projectName"] = QString::fromStdString(projectName);
        jsonObj["width"] = width;
        jsonObj["height"] = height;

        // Put all sprites into the JSON array
        QJsonArray spriteArray;
        for (const auto &sprite : sprites)
        {
            spriteArray.append(sprite.toJson());
        }
        jsonObj["sprites"] = spriteArray;

        return jsonObj;
    }

private:
    int width;
    int height;
    std::string projectName;

    int currentFrame;

    Timeline timeline;
    Palette palette;

    std::vector<Sprite> sprites;

    void emitIfNextOrPreviousSprites();

signals:
    void currentSpriteUpdated(Sprite *currentSprite);
    void currentSpriteID(int spriteID);

    void updateSpriteSizeUI(int x, int y);

    void canPlayAnimation(bool canPlay);

    void isThereNextSprite(bool validNextSprite);

    void isTherePreviousSprite(bool validPreviousSprite);

public slots:
    void paintedCurrentSpriteAt(int x, int y);
    void erasedCurrentSpriteAt(int x, int y);

    // Returns true if operation was a success
    void saveToJson(QString &file);

    // Returns true if operation was a success
    void loadJson(QString &file);

    void goToNextSprite();
    void goToPreviousSprite();
    void addSprite();
    void removeSprite();
};

#endif // SPRITESHEET_H
