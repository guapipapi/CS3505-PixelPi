#include "pixelpi.h"

#include <QApplication>
#include <QMainWindow>
#include <spritesheet.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPi w;
    w.show();

    Spritesheet spritesheet;

    // initialize default project
    spritesheet.newProject(256,256);

    return a.exec();
}
