#include "pixelpi.h"

#include <QApplication>
#include <QMainWindow>
#include <spritesheet.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPi w;
    w.show();

    // initialize default project
    Spritesheet spritesheet;

    // Connects spritesheet to paintWidget
    QObject::connect(&spritesheet, &Spritesheet::currentSpriteUpdated, &w, &PixelPi::updateSpriteWidget);

    // Initializes default project as 32 by 32 sprite
    spritesheet.newProject(32,32);


    return a.exec();
}
