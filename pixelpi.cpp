#include "pixelpi.h"
#include "ui_pixelpi.h"
#include <iostream>
#include <QPainter>
#include "paintWidget.h"
#include "spritesheet.h"
#include "sprite.h"
PixelPi::PixelPi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PixelPi)
{
    ui->setupUi(this);

    // THIS WILL BE MOVED TO MAIN.CPP here for testing purposes
    Sprite* newSprite = new Sprite(128,128);
    ui->paintWidget->setSprite(newSprite);

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




