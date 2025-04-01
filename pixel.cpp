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

void Pixel::setRedValue(unsigned char r) {
    this->r = r;
}

void Pixel::setGreenValue(unsigned char g) {
    this->g = g;
}

void Pixel::setBlueValue(unsigned char b) {
    this->b = b;
}

void Pixel::setAlphaValue(unsigned char a) {
    this->a = a;
}

// Checked by Scott Ceja
