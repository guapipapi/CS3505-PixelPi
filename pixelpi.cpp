#include "pixelpi.h"
#include "ui_pixelpi.h"
#include <QPainter>
#include "paintWidget.h"
#include "brush.h"
#include "pixel.h"
#include "sprite.h"
#include "fileDialog.h"

PixelPi::PixelPi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PixelPi)
{
    ui->setupUi(this);

    // THIS WILL BE MOVED TO MAIN.CPP here for testing purposes
    Brush* brush = new Brush(ui->paintWidget);
    brush->setRadius(2);
    Pixel* pixel = new Pixel(255, 0, 0, 255);
    ui->paintWidget->setBrush(brush);
    ui->paintWidget->setPixel(pixel);

    QObject::connect(&fileDialog, &FileDialog::createNewFileSignal, this, &PixelPi::createNewFile);
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

void PixelPi::updateSpriteWidget(Sprite *newSprite)
{
    ui->paintWidget->setSprite(newSprite);
}




void PixelPi::on_FileButton_clicked()
{
    fileDialog.show();
}

