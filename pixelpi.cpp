#include <QPainter>
#include <QColorDialog>
#include <QKeyEvent>
#include "pixelpi.h"
#include "ui_pixelpi.h"
#include "paintWidget.h"
#include "brush.h"
#include "pixel.h"
#include "sprite.h"
#include "fileDialog.h"

PixelPi::PixelPi(QWidget *parent) : QMainWindow(parent), ui(new Ui::PixelPi)
{
    ui->setupUi(this);

    QColor primaryColor(255, 0, 0, 255);   // Red
    QColor secondaryColor(0, 0, 255, 255); // Blue

    // Set button background colors
    QString primaryStyleSheet = QString("background-color: rgba(%1, %2, %3, %4);")
                                    .arg(primaryColor.red())
                                    .arg(primaryColor.green())
                                    .arg(primaryColor.blue())
                                    .arg(primaryColor.alpha());

    QString secondaryStyleSheet = QString("background-color: rgba(%1, %2, %3, %4);")
                                      .arg(secondaryColor.red())
                                      .arg(secondaryColor.green())
                                      .arg(secondaryColor.blue())
                                      .arg(secondaryColor.alpha());

    ui->primary_color_button->setStyleSheet(primaryStyleSheet);
    ui->secondary_color_button->setStyleSheet(secondaryStyleSheet);

    // THIS WILL BE MOVED TO MAIN.CPP here for testing purposes
    Brush *brush = new Brush(ui->paintWidget);
    brush->setRadius(2);

    Pixel *pixel = new Pixel(255, 0, 0, 255);

    ui->paintWidget->setBrush(brush);
    ui->paintWidget->setPixel(pixel);

    // Connect new file signal
    QObject::connect(&fileDialog, &FileDialog::createNewFileSignal, this, &PixelPi::createNewFile);
    QObject::connect(&fileDialog, &FileDialog::createNewFileSignal, this, &PixelPi::setNewSpriteDimensions);

    // Connect paint event to signal
    QObject::connect(ui->paintWidget, &PaintWidget::mouseClickedAt, this, &PixelPi::mousePaintedAt);
}

PixelPi::~PixelPi()
{
    delete ui;
}

// int zoomLevel;
// int zoomX;
// int zoomY;

void PixelPi::increaseZoom()
{
    zoomLevel *= 1.5;
}

void PixelPi::dragZoom(int newX, int newY)
{
    zoomX = newX;
    zoomY = newY;
}

void PixelPi::resetZoom()
{
    zoomLevel = 0;

    // zoomX = ...
    // zoomY = ...
    // LOGIC SHOULD BE ADDED TO THE PAINT WIDGET THAT GETS THE CENTRE OF THE CANVAS!!
}

void PixelPi::updateSpriteWidget(Sprite *newSprite)
{
    ui->paintWidget->setSprite(newSprite);
}

void PixelPi::updateCurrentPixel(const Pixel &pixel)
{
    // Create a non-const copy to work with
    Pixel newPixel = pixel;

    // Create a new pixel with the updated color values
    Pixel *updatedPixel = new Pixel(newPixel.getRedValue(), newPixel.getGreenValue(),
                                    newPixel.getBlueValue(), newPixel.getAlphaValue());

    // Set the new pixel to the paint widget
    ui->paintWidget->setPixel(updatedPixel);
}

void PixelPi::on_FileButton_clicked()
{
    fileDialog.show();
}

void PixelPi::on_primary_color_button_clicked()
{
    // Get current button background color as initial color
    QColor currentColor = ui->primary_color_button->palette().color(QPalette::Button);

    // Show color dialog with alpha channel support
    QColor selectedColor = QColorDialog::getColor(currentColor, this, "Choose Primary Color",
                                                  QColorDialog::ShowAlphaChannel);

    if (selectedColor.isValid())
    {
        // Create Pixel object from selected color
        Pixel pixel(selectedColor.red(), selectedColor.green(), selectedColor.blue(), selectedColor.alpha());

        // Update button appearance
        QString styleSheet = QString("background-color: rgba(%1, %2, %3, %4);")
                                 .arg(selectedColor.red())
                                 .arg(selectedColor.green())
                                 .arg(selectedColor.blue())
                                 .arg(selectedColor.alpha());

        ui->primary_color_button->setStyleSheet(styleSheet);

        // Emit signal to update the primary color in the application
        emit changePrimaryColor(pixel);
    }
}

void PixelPi::on_secondary_color_button_clicked()
{
    // Get current button background color as initial color
    QColor currentColor = ui->secondary_color_button->palette().color(QPalette::Button);

    // Show color dialog with alpha channel support
    QColor selectedColor = QColorDialog::getColor(currentColor, this, "Choose Secondary Color",
                                                  QColorDialog::ShowAlphaChannel);

    if (selectedColor.isValid())
    {
        // Create Pixel object from selected color
        Pixel pixel(selectedColor.red(), selectedColor.green(), selectedColor.blue(), selectedColor.alpha());

        // Update button appearance
        QString styleSheet = QString("background-color: rgba(%1, %2, %3, %4);")
                                 .arg(selectedColor.red())
                                 .arg(selectedColor.green())
                                 .arg(selectedColor.blue())
                                 .arg(selectedColor.alpha());

        ui->secondary_color_button->setStyleSheet(styleSheet);

        // Emit signal to update the secondary color in the application
        emit changeSecondaryColor(pixel);
    }
}

void PixelPi::keyPressEvent(QKeyEvent *event)
{
    // Check if the 'x' key was pressed
    if (event->key() == Qt::Key_X)
    {
        // Emit the switchColors signal to swap primary and secondary colors
        emit switchColors();

        // Swap the button styles to reflect the color swap visually
        QString primaryStyle = ui->primary_color_button->styleSheet();
        QString secondaryStyle = ui->secondary_color_button->styleSheet();

        ui->primary_color_button->setStyleSheet(secondaryStyle);
        ui->secondary_color_button->setStyleSheet(primaryStyle);
    }

    // Call the parent class implementation for other keys
    QMainWindow::keyPressEvent(event);
}

void PixelPi::on_brushRadiusSpinBox_valueChanged(int newRadius)
{
    emit newBrushRadius(newRadius);
}

void PixelPi::showHelpPage(){
    on_showHelpButton_clicked();
}

void PixelPi::on_showHelpButton_clicked()
{
    helpDialog.show();
    helpDialog.setModal(false);
}

void PixelPi::setNewSpriteDimensions(int x, int y){
    QString dimensionsText = QString("%1 x %2").arg(x).arg(y);
    ui->dimensionsLabel->setText(dimensionsText);
}

