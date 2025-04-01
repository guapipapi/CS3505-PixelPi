/**
 * @author Roland Guerriere
 *
 * The eraser class that extends the brush class, manages the romoval of pixels
 */
#ifndef ERASER_H
#define ERASER_H

#include <QObject>
#include "brush.h"

class Eraser : public Brush
{
public:
    /**
     * @param parent - The QObject for the eraser to work with
     */
    Eraser(QObject *parent = nullptr);

    /**
     * Overrids the paintPixel from brush, instead will remove pixels from the sprite
     * @param x - the x coordinate of the pixel
     * @param y - the y coordinate of the pixel
     * @param pixel - the pixel data to be written
     * @param sprite - the sprite to be operated on
     */
    void paintPixel(int x, int y, Pixel& pixel, Sprite& sprite) override;
};

#endif // ERASER_H

// - Checked by Scott Ceja
