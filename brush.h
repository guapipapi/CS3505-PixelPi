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
    virtual void paintPixel(int x, int y, Pixel& pixel, Sprite& sprite);

private:
    int radius;
public slots:
    void setRadius(int radius);

signals:
};

#endif // BRUSH_H
