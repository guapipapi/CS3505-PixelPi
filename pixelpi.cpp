#include "pixelpi.h"
#include "ui_pixelpi.h"
#include <iostream>
#include <QPainter>
#include "paintWidget.h"
#include "spritesheet.h"
#include "sprite.h"
#include "brush.h"
#include "pixel.h"
PixelPi::PixelPi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PixelPi)
{
    ui->setupUi(this);

    // THIS WILL BE MOVED TO MAIN.CPP here for testing purposes
    Sprite* newSprite = new Sprite(32,32);
    Brush* brush = new Brush(ui->paintWidget);
    brush->setRadius(2);
    Pixel* pixel = new Pixel(255, 0, 0, 255);
    ui->paintWidget->setSprite(newSprite);
    ui->paintWidget->setBrush(brush);
    ui->paintWidget->setPixel(pixel);

}

PixelPi::~PixelPi()
{
    delete ui;
}

//int zoomLevel;
//int zoomX;
//int zoomY;

void PixelPi::increaseZoom() {
    zoomLevel *= 1.5;
}

void PixelPi::dragZoom(int newX, int newY) {
    zoomX = newX;
    zoomY = newY;
}

void PixelPi::resetZoom() {
    zoomLevel = 0;

    //zoomX = ...
    //zoomY = ...
    //LOGIC SHOULD BE ADDED TO THE PAINT WIDGET THAT GETS THE CENTRE OF THE CANVAS!!
}




