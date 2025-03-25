#include "sprite.h"
#include "pixel.h"
#include <map>

Sprite::Sprite() { }

void Sprite::addPixel(int x, int y, Pixel pixel) {
    backing[std::pair<int, int>(x, y)] = pixel;
}

Pixel Sprite::getPixelAt(int x, int y) {
    return backing[std::pair(x, y)];
}

void Sprite::removePixelAt(int x, int y) {
    backing.erase(std::pair(x, y));
}
