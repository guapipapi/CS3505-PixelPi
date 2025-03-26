#include "pixelpi.h"
#include "ui_pixelpi.h"
#include <iostream>
#include <QPainter>
#include "paintWidget.h"  // Include your new class

PixelPi::PixelPi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PixelPi)
{
    ui->setupUi(this);

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




