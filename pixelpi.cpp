#include "pixelpi.h"
#include "ui_pixelpi.h"

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
