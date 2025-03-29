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
        pen.setWidth(10);
        painter.setPen(pen);

        for(int x = 0; x < sprite->width; x++) {
            for(int y = 0; y < sprite->height; y++) {
                if(sprite->getPixelAt(x, y) != nullptr) {
                    QRect rect(x, y, 2, 2);
                    painter.drawRect(rect);
                }
            }
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton && sprite != nullptr) {
            Pixel newPixel(0, 0, 0, 0);
            sprite->addPixel(event->pos().x(), event->pos().y(), newPixel);
            update();
        }
    }
};


#endif // PAINTWIDGET_H
