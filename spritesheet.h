/**
 * @author: Carlos Alatorre
 *
 * The spritesheet class is a model that handles all related buttons
 * and activity from the user related to the use of the sprites.
 */
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
    /**
     * Constructs the a QObject and current status of a palette
     * @param parent - pointer to a parent QObject
     */
    explicit Spritesheet(QObject *parent = nullptr);

    /**
     * This method returns the current sprite from the spritesheet
     * @return - the current sprite
     */
    Sprite &getCurrentSprite();

    /**
     * This method creates a new instance of a frame/sprite for the user to work on
     * @param newWidth - the new width value
     * @param newHeight - the new height value
     */
    void newProject(int newWidth, int newHeight);


                 /**
                  * This method returns the current palette
                  * @return - the current palette
                  */
        Palette & getPalette();

    /**
     * Gets the current timeline of the spritesheet
     * @return - the current timeline
     */
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
    // Boundaries
    int width;
    int height;

    std::string projectName;

    int currentFrame;

    // Portions of whole program
    Timeline timeline;
    Palette palette;

    std::vector<Sprite> sprites;

    void emitIfNextOrPreviousSprites();

signals:

                 /**
                  * This is a signal that updates the current sprite
                  * @param currentSprite - the current sprite to be updated
                  */
        void currentSpriteUpdated(Sprite * currentSprite);

    void currentSpriteID(int spriteID);

    void updateSpriteSizeUI(int x, int y);

    void canPlayAnimation(bool canPlay);

    void isThereNextSprite(bool validNextSprite);

    void isTherePreviousSprite(bool validPreviousSprite);

public slots:
    /**
     * This method gets the current coordinates of where the
     * current sprite is being painted
     * @param x - the x coordinate
     * @param y - the y coordinate
     */
    void paintedCurrentSpriteAt(int x, int y);

    /**
     * This method gets the current coordinates of where the current
     * sprite is erased
     * @param x - the x coordinate
     * @param y - the y coordinate
     */
    void erasedCurrentSpriteAt(int x, int y);

    /**
     * This method saves the current sprite to a JSON for the user
     * @param filePath - the current file path where the user wants to save
     * @return - true if file was able to be saved, false otherwise
     */
    void saveToJson(QString &file);

    /**
     * This method loads a sprite from a JSON to the current sprite sheet
     * @param filePath - the current file path the user is using to load sprite
     * @return - true if the file was able to be loaded, false otherwise
     */
    void loadJson(QString &file);

    void goToPreviousSprite();
    /**
     * Goes to the next sprite
     */
    void goToNextSprite();

    /**
     * Adds current sprite to the spritesheet
     */
    void addSprite();

    /**
     * Removes current sprite
     */
    void removeSprite();
};
#endif // SPRITESHEET_H
// - Checked by
