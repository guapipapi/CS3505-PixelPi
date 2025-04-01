/**
 * @authors: Roland Guerriere
 *
 * The PaintWidget class provides an interactive canvas for editing sprites.
 * It handles drawing of the sprite and processes mouse and wheel events for
 * painting, erasing, and zooming functionalities.
 */
#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "sprite.h"
#include "pixel.h"
#include "brush.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * Constructor for the PaintWidget.
     * @param parent - Pointer to the parent widget.
     */
    explicit PaintWidget(QWidget *parent);

    /**
     * Sets the sprite to be displayed and edited.
     * @param newSprite - Pointer to the new Sprite object.
     */
    void setSprite(Sprite *newSprite);

    /**
     * Clears the current sprite from the widget.
     */
    void clearSprite();

    /**
     * Sets the brush used for painting.
     * @param brush - Pointer to the Brush object.
     */
    void setBrush(Brush *brush);

    /**
     * Sets the pixel used for painting.
     * @param pixel - Pointer to the Pixel object.
     */
    void setPixel(Pixel *pixel);

private:
    /**
     * Pointer to the sprite currently being edited.
     */
    Sprite* sprite = nullptr;

    /**
     * Pointer to the current pixel used for drawing.
     */
    Pixel* pixel = nullptr;

    /**
     * Pointer to the brush for painting operations.
     */
    Brush* brush = nullptr;

    /**
     * Current zoom factor for the canvas.
     */
    double zoom = 1;

    /**
     * Size of each pixel block in the widget.
     */
    int pixelSize = 0;

    /**
     * Horizontal offset for drawing the sprite.
     */
    int offsetX = 0;

    /**
     * Vertical offset for drawing the sprite.
     */
    int offsetY = 0;

    /**
     * Flag indicating if wheel dragging is active.
     */
    bool wheelDragging = false;

    /**
     * Stores the mouse position when starting a drag operation.
     */
    QPoint mouseDragPos;

protected:
    /**
     * Overrides the paint event to render the sprite and grid.
     * @param event - Pointer to the QPaintEvent.
     */
    void paintEvent(QPaintEvent *) override;

    /**
     * Handles mouse press events for painting or erasing.
     * @param event - Pointer to the QMouseEvent.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * Handles mouse movement events for painting or dragging.
     * @param event - Pointer to the QMouseEvent.
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * Handles wheel events for zooming in and out.
     * @param event - Pointer to the QWheelEvent.
     */
    void wheelEvent(QWheelEvent *event) override;

    /**
     * Handles mouse release events to conclude drag or painting operations.
     * @param event - Pointer to the QMouseEvent.
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    /**
     * Signal emitted when the mouse is clicked at a specific coordinate.
     * @param x - X coordinate of the click.
     * @param y - Y coordinate of the click.
     */
    void mouseClickedAt(int x, int y);

    /**
     * Signal emitted when an erase action occurs at a specific coordinate.
     * @param x - X coordinate of the erase action.
     * @param y - Y coordinate of the erase action.
     */
    void erasedAt(int x, int y);
};

#endif // PAINTWIDGET_H

// - Checked by Imran Khalil
