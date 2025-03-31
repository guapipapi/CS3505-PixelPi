#include "palette.h"
#include "pixel.h"

Palette::Palette(QObject *parent) : QObject{parent}
{
    this->currentColor = Pixel(255, 0, 0, 255);
    this->secondaryColor = Pixel(255, 0, 0, 255);
}

void Palette::setNewCurrentColor(const Pixel &pixel)
{
    this->currentColor = pixel;
    emit currentColorChanged(pixel);
}

void Palette::setNewSecondaryColor(const Pixel &pixel)
{
    this->secondaryColor = pixel;
}

void Palette::switchToSecondaryColor()
{
    std::swap(currentColor, secondaryColor);
    emit currentColorChanged(currentColor);
}

Pixel &Palette::getCurrentColor()
{
    return currentColor;
}

Brush* Palette::getBrush(){
    return &brush;
}
