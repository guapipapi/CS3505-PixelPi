#include "sprite.h"
#include "pixel.h"
#include <map>

Sprite::Sprite() { }

void Sprite::addPixel(int x, int y, Pixel& newPixel) {
    backing.insert({{x, y}, newPixel});
}

Pixel* Sprite::getPixelAt(int x, int y) {
    auto it = backing.find({x, y});
    return (it != backing.end()) ? &it->second : nullptr;
}

void Sprite::removePixelAt(int x, int y) {
    backing.erase(std::pair(x, y));
}
