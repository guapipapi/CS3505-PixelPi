#include "pixelpi.h"
#include "brush.h"
#include "spritesheet.h"
#include "palette.h"

#include <QApplication>
#include <QMainWindow>
#include <spritesheet.h>
#include <brush.h>
#include <palette.h>
#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPi w;
    Controller controller;

    w.show();

    // initialize default project
    Spritesheet spritesheet;



    // Connects spritesheet to paintWidget
    QObject::connect(&spritesheet, &Spritesheet::currentSpriteUpdated, &w, &PixelPi::updateSpriteWidget);

    // Connects new file button
    QObject::connect(&w, &PixelPi::createNewFile, &spritesheet, &Spritesheet::newProject);



    // Initializes default project as 32 by 32 sprite
    spritesheet.newProject(32, 32);

    // Connect color change signals from PixelPi to Palette
    QObject::connect(&w, &PixelPi::changePrimaryColor, &spritesheet.getPalette(), &Palette::setNewCurrentColor);
    QObject::connect(&w, &PixelPi::changeSecondaryColor, &spritesheet.getPalette(), &Palette::setNewSecondaryColor);
    QObject::connect(&w, &PixelPi::switchColors, &spritesheet.getPalette(), &Palette::switchToSecondaryColor);

    QObject::connect(&spritesheet.getPalette(), &Palette::currentColorChanged, &w, &PixelPi::updateCurrentPixel);

    QObject::connect(&w, &PixelPi::newBrushRadius, spritesheet.getPalette().getBrush(), &Brush::setRadius);

    QObject::connect(&w, &PixelPi::mousePaintedAt, &spritesheet, &Spritesheet::paintedCurrentSpriteAt);

    w.showHelpPage();

    return a.exec();
}
