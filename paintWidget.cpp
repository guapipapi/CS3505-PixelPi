#include "paintWidget.h"
#include "brush.h"
#include "pixel.h"
#include <QWidget>

PaintWidget::PaintWidget(QWidget *parent) : QWidget{parent} {
    // Allow for dragging
    setMouseTracking(true);
}

void PaintWidget::setSprite(Sprite *newSprite) {
    this->sprite = newSprite;
}

void PaintWidget::setBrush(Brush *brush) {
    this->brush = brush;
}

void PaintWidget::setPixel(Pixel *pixel) {
    this->pixel = pixel;
}
