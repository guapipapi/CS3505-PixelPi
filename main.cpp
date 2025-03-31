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

    // Create brush and palette
    Brush brush;
    Palette palette(nullptr, brush);

    // Connects spritesheet to paintWidget
    QObject::connect(&spritesheet, &Spritesheet::currentSpriteUpdated, &w, &PixelPi::updateSpriteWidget);

    // Connects new file button
    QObject::connect(&w, &PixelPi::createNewFile, &spritesheet, &Spritesheet::newProject);

    // Connect color change signals from PixelPi to Palette
    QObject::connect(&w, &PixelPi::changePrimaryColor, &palette, &Palette::setNewCurrentColor);
    QObject::connect(&w, &PixelPi::changeSecondaryColor, &palette, &Palette::setNewSecondaryColor);
    QObject::connect(&w, &PixelPi::switchColors, &palette, &Palette::switchToSecondaryColor);

    QObject::connect(&palette, &Palette::currentColorChanged, &w, &PixelPi::updateCurrentPixel);

    // Initializes default project as 32 by 32 sprite
    spritesheet.newProject(32, 32);

    QObject::connect(&w, &PixelPi::newBrushRadius, &brush, &Brush::setRadius);

    w.showHelpPage();

    return a.exec();
}
