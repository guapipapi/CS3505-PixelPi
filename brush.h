#ifndef BRUSH_H
#define BRUSH_H

#include <QObject>
#include "sprite.h"

class Brush : public QObject
{
    Q_OBJECT
public:
    explicit Brush(QObject *parent = nullptr);
    int getRadius();
    void setRadius(int radius);
    void paintPixel(int x, int y, Pixel& pixel, Sprite& sprite);
private:
    int radius;

signals:
};

#endif // BRUSH_H
