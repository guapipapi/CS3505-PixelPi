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





