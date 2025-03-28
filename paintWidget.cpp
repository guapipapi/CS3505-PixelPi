#include "paintWidget.h"
#include <QWidget>

PaintWidget::PaintWidget(QWidget *parent) : QWidget{parent} {}

void PaintWidget::setSprite(Sprite *newSprite) {
    this->sprite = newSprite;
}
