#include "brush.h"

Brush::Brush(QObject *parent) : QObject{parent}, radius{1} {}

int Brush::getRadius() {
    return radius;
}

void Brush::setRadius(int radius) {
    this->radius = radius;
}

void Brush::paintPixel(int x, int y, Pixel& pixel, Sprite& sprite) {
    sprite.addPixel(x, y, pixel);
}

// Checked by Scott Ceja
