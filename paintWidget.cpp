#include "paintWidget.h"
#include "brush.h"
#include "pixel.h"
#include <QWidget>

PaintWidget::PaintWidget(QWidget *parent) : QWidget{parent} {
    // Allow for dragging
    setMouseTracking(true);
}

void PaintWidget::setSprite(Sprite *newSprite) {
    this->sprite = newSprite;
}

void PaintWidget::setBrush(Brush *brush) {
    this->brush = brush;
}

void PaintWidget::setPixel(Pixel *pixel) {
    this->pixel = pixel;
}


void PaintWidget::paintEvent(QPaintEvent *){
    if (sprite == nullptr || brush == nullptr || pixel == nullptr)
        return;

    QPainter painter(this);
    // No outline
    painter.setPen(Qt::NoPen);

    int pixelSize = this->width()/sprite->width;

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

    if(event->button() == Qt::LeftButton) {
        int pixelSize = this->width()/sprite->width;
        int xCoord = event->pos().x()/pixelSize;
        int yCoord = event->pos().y()/pixelSize;

        int r = brush->getRadius();
        for(int x = -r/2; x <= r/2; x++) {
            for(int y = -r/2; y <= r/2; y++) {
                int px = xCoord + x;
                int py = yCoord + y;

                // Bounds check
                if (px >= 0 && px < sprite->width && py >= 0 && py < sprite->height) {
                    sprite->addPixel(px, py, *pixel);
                }
            }
        }
    }
    update();
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
    if (sprite == nullptr || brush == nullptr || pixel == nullptr)
        return;

    if (event->buttons() & Qt::LeftButton) {
        int pixelSize = this->width() / sprite->width;
        int xCoord = event->pos().x() / pixelSize;
        int yCoord = event->pos().y() / pixelSize;

        int radius = brush->getRadius();
        int halfRadius = radius / 2;

        for (int dx = -halfRadius; dx <= halfRadius; dx++) {
            for (int dy = -halfRadius; dy <= halfRadius; dy++) {
                int px = xCoord + dx;
                int py = yCoord + dy;

                if (px >= 0 && px < sprite->width && py >= 0 && py < sprite->height) {
                    sprite->addPixel(px, py, *pixel);
                }
            }
        }

        update();
    }
}
