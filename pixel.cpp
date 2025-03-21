#include "pixel.h"

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

unsigned char Pixel::getRedValue() {
    return r;
}

unsigned char Pixel::getGreenValue() {
    return g;
}

unsigned char Pixel::getBlueValue() {
    return b;
}

unsigned char Pixel::getAlphaValue() {
    return a;
}
