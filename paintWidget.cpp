#include "paintWidget.h"
#include "brush.h"
#include "pixel.h"
#include <QWidget>
#include <QWheelEvent>

PaintWidget::PaintWidget(QWidget *parent) : QWidget{parent} {
    // Allow for dragging
    setMouseTracking(true);
}

void PaintWidget::setSprite(Sprite *newSprite) {
    this->sprite = newSprite;
    this->zoom = 1;
    this->offsetX = 0;
    this->offsetY = 0;
}

void PaintWidget::setBrush(Brush *brush) {
    this->brush = brush;
}

void PaintWidget::setPixel(Pixel *pixel) {
    this->pixel = pixel;
}


/**
 * @brief PaintWidget::paintEvent
 * Draws pixels based on sprite object
 */
void PaintWidget::paintEvent(QPaintEvent *){

    if (sprite == nullptr || brush == nullptr || pixel == nullptr)
        return;

    QPainter painter(this);
    // No outline
    painter.setPen(Qt::NoPen);

    pixelSize = qMax(1, (this->width() / sprite->width) * (int)zoom);
    painter.translate(offsetX, offsetY);

    for(int x = 0; x < sprite->width; x++) {
        for(int y = 0; y < sprite->height; y++) {
            if(sprite->getPixelAt(x, y) != nullptr) {
                Pixel* p = sprite->getPixelAt(x, y);
                painter.setBrush(QColor(p->getRedValue(), p->getGreenValue(), p->getBlueValue(), p->getAlphaValue()));

                QRect rect(x*pixelSize, y*pixelSize, pixelSize, pixelSize);
                painter.drawRect(rect);
            }
        }
    }
}

void PaintWidget::mousePressEvent(QMouseEvent *event) {
    if (sprite == nullptr || brush == nullptr || pixel == nullptr)
        return;

    //Only allow drawing pixels if the canvas isn't being dragged!
    if (!wheelDragging) {

        //If the left button is being pressed draw a pixel
        if(event->button() == Qt::LeftButton) {
            //pixelSize = this->width()/sprite->width;
            int xCoord = (event->pos().x() - offsetX) / pixelSize;
            int yCoord = (event->pos().y() - offsetY) / pixelSize;

            // Emits the mouse position in sprite coordinates
            emit mouseClickedAt(xCoord, yCoord);

            // DRAWING


        //If the middle button is being pressed start to drag the canvas
        } else if (event->button() == Qt::MiddleButton) {
            wheelDragging = true; //Set dragging to true!
            mouseDragPos = event->pos(); //Store the starting position of the drag
            setCursor(Qt::ClosedHandCursor); //Change cursor to the drag symbol
        }

        update();
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
    if (sprite == nullptr || brush == nullptr || pixel == nullptr)
        return;

    //If the middle button is being pressed then drag the canvas around
    if (wheelDragging) {

        //Calculate the distance between the original and current mouse postion
        QPoint distance = event->pos() - mouseDragPos;

        //Apply the distance to the current canvas offset
        offsetX += distance.x();
        offsetY += distance.y();

        //Determine the boundries of the canvas
        int canvasWidth = pixelSize * sprite->width;
        int canvasHeight = pixelSize * sprite->height;

        //Make sure the offset stays inside the boundries of the canvas
        offsetX = qMin(0, qMax(offsetX, this->width() - canvasWidth));
        offsetY = qMin(0, qMax(offsetY, this->height() - canvasHeight));

        //Update the original mouse dragged position
        mouseDragPos = event->pos();

    } else {

        if (event->buttons() & Qt::LeftButton) {
            //pixelSize = this->width() / sprite->width;
            int xCoord = (event->pos().x() - offsetX) / pixelSize;
            int yCoord = (event->pos().y() - offsetY) / pixelSize;

            int radius = brush->getRadius();
            int halfRadius = radius / 2;

            for (int dx = -halfRadius; dx <= halfRadius; dx++) {
                for (int dy = -halfRadius; dy <= halfRadius; dy++) {
                    int px = xCoord + dx;
                    int py = yCoord + dy;

                    // bounds check
                    if (px >= 0 && px < sprite->width && py >= 0 && py < sprite->height) {
                        sprite->addPixel(px, py, *pixel);
                    }
                }
            }
        }
    }

    update();
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {

    //Set dragging to false if the middle button was released
    if (event->button() == Qt::MiddleButton) {
        wheelDragging = false; //Set dragging to false!
        setCursor(Qt::ArrowCursor); //Reset cursor
    }
}

void PaintWidget::wheelEvent(QWheelEvent *event) {

    if (sprite == nullptr)
        return;

    //Only allow zooming in if the canvas isn't being dragged around!
    if (!wheelDragging) {

        //Get the mouse position and angle of the scrolling
        QPointF mousePos = event->position();
        int delta = event->angleDelta().y();

        int prevPixelSize = pixelSize;

        //Apply zoom
        if (delta >= 0) {
            if (zoom < 3) {
                zoom *= 1.5;
            } else {
                zoom *= 1.1;
            }
        } else {
            zoom = 1;  //Reset zoom
        }

        //Calculate the new pixel size after zooming
        pixelSize = qMax(1.0, (this->width() / sprite->width) * zoom);

        //If there's no zoom set offsets to zero
        if (zoom == 1) {
            offsetX = 0;
            offsetY = 0;

        //Calculate how to draw the canvas based on the current zoom
        } else {

            //Adjust the offsets based on the mouse position and the new zoom level
            offsetX += (mousePos.x() - offsetX) * (1 - (pixelSize / prevPixelSize));
            offsetY += (mousePos.y() - offsetY) * (1 - (pixelSize / prevPixelSize));

            //Make sure the offset stays inside the boundries of the canvas
            int canvasWidth = pixelSize * sprite->width;
            int canvasHeight = pixelSize * sprite->height;

            //Check horizontal offset
            if (offsetX > 0) {
                offsetX = 0;
            } else if (offsetX < (this->width() - canvasWidth)) {
                offsetX = this->width() - canvasWidth;
            }

            //Check vertical offset
            if (offsetY > 0) {
                offsetY = 0;
            } else if (offsetY < (this->height() - canvasHeight)) {
                offsetY = this->height() - canvasHeight;
            }
        }

        update();
    }
}
