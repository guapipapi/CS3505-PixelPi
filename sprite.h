#ifndef SPRITE_H
#define SPRITE_H

#include <pixel.h>
#include <QObject>

class Sprite
{
public:
    Sprite();

    void addPixel(int x, int y, Pixel& newPixel);
    void removePixelAt(int x, int y);
    Pixel* getPixelAt(int x, int y);
signals:
    void spriteUpdated();
private:
    std::map<std::pair<int, int>, Pixel> backing;
};

#endif // SPRITE_H
