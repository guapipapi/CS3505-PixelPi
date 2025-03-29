#ifndef ERASER_H
#define ERASER_H

#include <QObject>
#include "brush.h"
class Eraser : public Brush
{
public:
    Eraser(QObject *parent = nullptr);
    void paintPixel(int x, int y, Pixel& pixel, Sprite& sprite) override;
};

#endif // ERASER_H
