/**
 * @author Roland Guerriere
 *
 * The brush class that controls functions for drawing to the sprite and managing the brush
 */
#ifndef BRUSH_H
#define BRUSH_H

#include <QObject>
#include "sprite.h"

class Brush : public QObject
{
    Q_OBJECT
public:
    /**
     * Constructs a new brush object that handels drawing to the sprite
     * @param parent - The QObject for the brush to bind to
     */
    explicit Brush(QObject *parent = nullptr);

    /**
     * Gets the radius of the brush
     * @return - the radius of the brush
     */
    int getRadius();

    /**
     * Draws a pixel to the sprite based on the x, y, and pixel
     * @param x - the x coordinate of the pixel
     * @param y - the y coordinate of the pixel
     * @param pixel - the pixel data to be drawn
     * @param sprite - the sprite to draw to
     */
    virtual void paintPixel(int x, int y, Pixel& pixel, Sprite& sprite);

private:
    // The radius of the brush
    int radius;

public slots:
    /**
     * Sets the radius of the brush
     * @param radius - the radius of the brush to be set to
     */
    void setRadius(int radius);
};

#endif // BRUSH_H

// - Checked by Scott Ceja
