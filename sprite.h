/**
 * @authors: Roland Guerriere
 *
 * The sprite class is a model that depicts all actions related to when
 * a sprite is being changed, including the pixel properties of it
 */
#ifndef SPRITE_H
#define SPRITE_H

#include <pixel.h>
#include <QObject>

class Sprite
{
public:
    /**
     * Constructor for the sprite
     * @param width - width of the sprite
     * @param height - height of the sprite
     */
    Sprite(int width, int height);

    /**
     * Default constructor, will make a 32x32 sprite
     */
    Sprite();

    // dimension
    int width;
    int height;

    /**
     * Adds a pixel to the canvas based on the x and y
     * @param x - X coordinate of the pixel
     * @param y - Y coordinate of the pixel
     * @param newPixel - Pixel data to be added
     */
    void addPixel(int x, int y, Pixel& newPixel);

    /**
     * Paints a pixel of the correct radius to the sprite
     * @param x - X coordinate of the pixel
     * @param y - Y coordinate of the pixel
     * @param radius - radius of the brush
     * @param newPixel - pixel to be painted
     */
    void paintAt(int x, int y, int radius, Pixel& newPixel);

    /**
     * Removes the radius^2 from  the sprite
     * @param x - X coordinate of the mouse
     * @param y - Y coordinate of the mouse
     * @param radius - radius of the brush
     */
    void eraseAt(int x, int y, int radius);

    /**
     * Removes a pixel at a specified coordinate
     * @param x - X coordinate of the pixel
     * @param y - Y coordinate of the pixel
     */
    void removePixelAt(int x, int y);

    /**
     * Gets the data of the pixel at the x y coordinates
     * @param x - X coordinate of the pixel
     * @param y - Y coordinate of the pixel
     * @return The pixel data
     */
    Pixel* getPixelAt(int x, int y);

    //Convert sprite data to JSON
    QJsonObject toJson() const;

    //Load Sprite from JSON and allow size to manually be set
    void fromJson(const QJsonObject& jsonObj);
    void setSize(int width, int height);

signals:
    /**
     * If the sprite is updated
     */
    void spriteUpdated();
private:
    // backing map of the sprite
    std::map<std::pair<int, int>, Pixel> backing;
};

#endif // SPRITE_H

// - Checked by Imran Khalil
