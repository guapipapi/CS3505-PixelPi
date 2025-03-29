#include "eraser.h"
#include <QObject>

Eraser::Eraser(QObject *parent) : Brush(parent) {}

void Eraser::paintPixel(int x, int y, Pixel& pixel, Sprite& sprite) {
    if (pixel.getAlphaValue() != 0)
        sprite.removePixelAt(x, y);
}
