#include "pixelpi.h"
#include "brush.h"
#include "spritesheet.h"
#include "palette.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPi w;
    w.show();

    // initialize default project
    Spritesheet spritesheet;

    // Create brush and palette
    Brush brush;
    Palette palette(nullptr, brush);

    // Connects spritesheet to paintWidget
    QObject::connect(&spritesheet, &Spritesheet::currentSpriteUpdated, &w, &PixelPi::updateSpriteWidget);
    QObject::connect(&w, &PixelPi::createNewFile, &spritesheet, &Spritesheet::newProject);

    // Connect color change signals from PixelPi to Palette
    QObject::connect(&w, &PixelPi::changePrimaryColor, &palette, &Palette::setNewCurrentColor);
    QObject::connect(&w, &PixelPi::changeSecondaryColor, &palette, &Palette::setNewSecondaryColor);
    QObject::connect(&w, &PixelPi::switchColors, &palette, &Palette::switchToSecondaryColor);

    QObject::connect(&palette, &Palette::currentColorChanged, &w, &PixelPi::updateCurrentPixel);


    // Initializes default project as 32 by 32 sprite
    spritesheet.newProject(32,32);


    return a.exec();
}
