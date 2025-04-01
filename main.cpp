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
#include <QString>
#include <timeline.h>

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

    QObject::connect(&spritesheet, &Spritesheet::currentSpriteID, &w, &PixelPi::updateCurrentSprite);

    // Connects new file button
    QObject::connect(&w, &PixelPi::createNewFile, &spritesheet, &Spritesheet::newProject);

    // Connects save and open file buttons
    QObject::connect(&w, &PixelPi::loadFile, &spritesheet, &Spritesheet::loadJson);
    QObject::connect(&w, &PixelPi::saveFile, &spritesheet, &Spritesheet::saveToJson);

    // Connects the load file procedure and size label in the UI
    QObject::connect(&spritesheet, &Spritesheet::updateSpriteSizeUI, &w, &PixelPi::setNewSpriteDimensions);

    // Initializes default project as 32 by 32 sprite
    spritesheet.newProject(32, 32);

    // Connect color change signals from PixelPi to Palette
    QObject::connect(&w, &PixelPi::changePrimaryColor, &spritesheet.getPalette(), &Palette::setNewCurrentColor);
    QObject::connect(&w, &PixelPi::changeSecondaryColor, &spritesheet.getPalette(), &Palette::setNewSecondaryColor);
    QObject::connect(&w, &PixelPi::switchColors, &spritesheet.getPalette(), &Palette::switchToSecondaryColor);

    QObject::connect(&spritesheet.getPalette(), &Palette::currentColorChanged, &w, &PixelPi::updateCurrentPixel);

    QObject::connect(&w, &PixelPi::newBrushRadius, spritesheet.getPalette().getBrush(), &Brush::setRadius);

    // Connect painting to spritesheet
    QObject::connect(&w, &PixelPi::mousePaintedAt, &spritesheet, &Spritesheet::paintedCurrentSpriteAt);

    // Connect erasing to spritesheet
    QObject::connect(&w, &PixelPi::mouseErasedAt, &spritesheet, &Spritesheet::erasedCurrentSpriteAt);

    // Connect fps spinBox
    QObject::connect(&w, &PixelPi::newFPS, &spritesheet.getTimeline(), &Timeline::changeFPS);

    QObject::connect(&w, &PixelPi::playAnimation, &spritesheet.getTimeline(), &Timeline::playAnimation);

    QObject::connect(&w, &PixelPi::addSprite, &spritesheet, &Spritesheet::addSprite);

    QObject::connect(&w, &PixelPi::removeSprite, &spritesheet, &Spritesheet::removeSprite);

    // Shows help page on start
    // TODO: uncomment this. Commented so we aren't bothered while testing
    // w.showHelpPage();

    return a.exec();
}
