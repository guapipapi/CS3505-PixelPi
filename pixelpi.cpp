#include "pixelpi.h"
#include "ui_pixelpi.h"
#include <iostream>

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



void PixelPi::on_FileButton_clicked()
{
    fileDialog.setModal(true);
    fileDialog.show();
}

