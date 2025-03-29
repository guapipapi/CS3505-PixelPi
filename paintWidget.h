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
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};


#endif // PAINTWIDGET_H
