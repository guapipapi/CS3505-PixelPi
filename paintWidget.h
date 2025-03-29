#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "sprite.h"
#include "pixel.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent);
    void setSprite(Sprite *newSprite);
    void clearSprite();

private:
    Sprite* sprite = nullptr;

protected:
    void paintEvent(QPaintEvent *) override {
        if (sprite == nullptr)
            return;

        QPainter painter(this);
        QPen pen(Qt::blue);
        // No outline
        painter.setPen(Qt::NoPen);

        // Solid fill color
        painter.setBrush(QBrush(Qt::blue));

        painter.setPen(pen);

        int pixelSize = this->width()/sprite->width;

        for(int x = 0; x < sprite->width; x++) {
            for(int y = 0; y < sprite->height; y++) {
                if(sprite->getPixelAt(x, y) != nullptr) {
                    QRect rect(x*pixelSize, y*pixelSize, pixelSize, pixelSize);
                    painter.drawRect(rect);
                }
            }
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton && sprite != nullptr) {
            int pixelSize = this->width()/sprite->width;
            int xCoord = event->pos().x()/pixelSize;
            int yCoord = event->pos().y()/pixelSize;

            Pixel newPixel(0, 0, 0, 0);
            sprite->addPixel(xCoord, yCoord, newPixel);
            update();
        }
    }
};


#endif // PAINTWIDGET_H
