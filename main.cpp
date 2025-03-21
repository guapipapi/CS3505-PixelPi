#include "pixelpi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PixelPi w;
    w.show();
    return a.exec();
}
