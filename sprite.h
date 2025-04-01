#ifndef SPRITE_H
#define SPRITE_H

#include <pixel.h>
#include <QObject>

class Sprite
{
public:
    Sprite(int width, int height);
    Sprite();

    int width;
    int height;

    void addPixel(int x, int y, Pixel& newPixel);
    void paintAt(int x, int y, int radius, Pixel& newPixel);

    void eraseAt(int x, int y, int radius);

    void removePixelAt(int x, int y);
    Pixel* getPixelAt(int x, int y);

    //Convert sprite data to JSON
    QJsonObject toJson() const;

    //Load Sprite from JSON and allow size to manually be set
    void fromJson(const QJsonObject& jsonObj);
    void setSize(int width, int height);

signals:
    void spriteUpdated();
private:
    std::map<std::pair<int, int>, Pixel> backing;
};

#endif // SPRITE_H
