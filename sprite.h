#ifndef SPRITE_H
#define SPRITE_H

#include <pixel.h>
#include <QObject>

class Sprite
{
public:
    Sprite();

    void addPixel(Pixel newPixel);
    void removePixelAt(int x, int y);
    void getPixelAt(int x, int y);
signals:
    void spriteUpdated();
private:

};

#endif // SPRITE_H
