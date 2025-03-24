#ifndef SPRITE_H
#define SPRITE_H

#include <pixel.h>
#include <QObject>

class Sprite
{
public:
    Sprite();

    void AddPixel(Pixel newPixel);
    void RemovePixelAt(int x, int y);
    void GetPixelAt(int x, int y);
signals:
    void SpriteUpdated();
private:

};

#endif // SPRITE_H
