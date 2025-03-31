#include "palette.h"
#include "pixel.h"

Palette::Palette(QObject *parent, Brush& brush) : QObject{parent}, brush{brush} {
    this->currentColor = Pixel(255, 0, 0, 255);
    this->secondaryColor = Pixel(255, 0, 0, 255);
}

void Palette::setNewCurrentColor(const Pixel& pixel) {
    this->currentColor = pixel;
    emit currentColorChanged(pixel);
}

void Palette::setNewSecondaryColor(const Pixel& pixel) {
    this->secondaryColor = pixel;
}

void Palette::switchToSecondaryColor() {
    std::swap(currentColor, secondaryColor);
    emit currentColorChanged(currentColor);
}

const Pixel& Palette::getCurrentColor() {
    return currentColor;
}

