/**
 * @authors: Carlos Alatorre
 *
 * The Palette class manages the color palette for the sprite editor.
 * It maintains the current primary and secondary colors and holds a brush instance.
 * It provides methods to update and retrieve colors and emits signals when changes occur.
 */
#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <pixel.h>
#include "brush.h"

class Palette : public QObject
{
    Q_OBJECT
public:
    /**
     * Constructor for the Palette class.
     * @param parent - Pointer to the parent QObject.
     */
    explicit Palette(QObject *parent);

    /**
     * Retrieves a pointer to the current brush used for painting.
     * @return Pointer to the Brush object.
     */
    Brush* getBrush();

private:
    /**
     * The current primary color used for painting.
     */
    Pixel currentColor;

    /**
     * The secondary color used for painting.
     */
    Pixel secondaryColor;

    /**
     * The brush instance for managing painting properties.
     */
    Brush brush;

signals:
    /**
     * Signal emitted when the current primary color is changed.
     * @param pixel - The new primary color.
     */
    void currentColorChanged(const Pixel &pixel);

public slots:
    /**
     * Sets a new primary color and emits the currentColorChanged signal.
     * @param pixel - The new primary color.
     */
    void setNewCurrentColor(const Pixel &pixel);

    /**
     * Sets a new secondary color.
     * @param pixel - The new secondary color.
     */
    void setNewSecondaryColor(const Pixel &pixel);

    /**
     * Switches the current primary color to the secondary color.
     */
    void switchToSecondaryColor();

    /**
     * Retrieves a reference to the current primary color.
     * @return Reference to the current primary Pixel.
     */
    Pixel &getCurrentColor();
};

#endif // PALETTE_H

// - Checked by Scott Ceja
