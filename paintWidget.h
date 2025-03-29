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
    explicit PaintWidget(QWidget *parent);
    void setSprite(Sprite *newSprite);
    void clearSprite();
    void setBrush(Brush *brush);
    void setPixel(Pixel *pixel);

private:
    Sprite* sprite = nullptr;
    Pixel* pixel = nullptr;
    Brush* brush = nullptr;

protected:
    void paintEvent(QPaintEvent *) override {
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

    void mousePressEvent(QMouseEvent *event) override {
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

    void mouseMoveEvent(QMouseEvent *event) override {
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

};


#endif // PAINTWIDGET_H
