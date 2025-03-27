#include "paintWidget.h"
#include <QWidget>

PaintWidget::PaintWidget(QWidget *parent, Sprite sprite) : QWidget{parent}, sprite{sprite} {}

void PaintWidget::setSprite(Sprite sprite) {
    this-> sprite = sprite;
}
