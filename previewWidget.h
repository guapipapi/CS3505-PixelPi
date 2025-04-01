/**
 * @author Imran Khalil
 *
 * The preview of the entire canvas in the bottom
 */
#ifndef PREVIEWWIDGET_H
#define PREVIEWWIDGET_H

#include <QWidget>
#include <QPainter>

#include <QMouseEvent>
#include "sprite.h"

/**
 * @Authors: ...
 *
 * This class represents the preview viewport in the UI.
 */
class PreviewWidget : public QWidget
{
    Q_OBJECT
public:

    // Default constructor
    explicit PreviewWidget(QWidget *parent);

    /**
     * Sets the sprite for the preview to use.
     * @param newSprite - the new sprite for the preview
     */
    void setSprite(Sprite* newSprite);

    /**
     * Updates the preview to reflect the changes of the current sprite.
     */
    void draw();

private:

    // Keeps track of the sprite being displayed on the preview
    Sprite* sprite = nullptr;

protected:

    // Override for the QT paint event
    void paintEvent(QPaintEvent* event) override;

};

#endif // PREVIEWWIDGET_H

// - Checked by Scott Ceja
