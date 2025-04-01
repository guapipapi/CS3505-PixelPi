#include "sprite.h"
#include "pixel.h"
#include <map>

/*
 * Constructor that takes in a widht and height for the sprite.
 */
Sprite::Sprite(int width, int height) {
    this->width = width;
    this->height = height;
}

/*
 * Default constructor that makes a 32x32 Sprite.
 */
Sprite::Sprite(){
    width = 32;
    height = 32;
}

void Sprite::addPixel(int x, int y, Pixel& newPixel) {
    if(getPixelAt(x, y) != nullptr)
        removePixelAt(x, y);
    backing.insert({{x, y}, newPixel});
}

Pixel* Sprite::getPixelAt(int x, int y) {
    auto px = backing.find({x, y});
    return (px != backing.end()) ? &px ->second : nullptr;
}

void Sprite::removePixelAt(int x, int y) {
    backing.erase(std::pair(x, y));
}

QJsonObject Sprite::toJson() const {
    QJsonObject jsonObj;
    QJsonObject pixelData;

    //Convert the map to the JSON format as {"(x,y)": {pixel data}}
    for (const auto& [coord, pixel] : backing) {
        QString key = QString("(%1,%2)").arg(coord.first).arg(coord.second);
        pixelData[key] = pixel.toJson();
    }

    jsonObj["backing"] = pixelData;
    return jsonObj;
}

void Sprite::fromJson(const QJsonObject& jsonObj) {
    backing.clear();

    if (!jsonObj.contains("backing") || !jsonObj["backing"].isObject()) return;

    QJsonObject pixelData = jsonObj["backing"].toObject();
    for (const QString& key : pixelData.keys()) {
        QJsonObject pixelObj = pixelData[key].toObject();

        Pixel pixel;
        pixel.fromJson(pixelObj);

        //Parse (x,y)
        int x, y;
        sscanf(key.toStdString().c_str(), "(%d,%d)", &x, &y);
        backing[{x, y}] = pixel;
    }
}

void Sprite::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

void Sprite::paintAt(int x, int y, int radius, Pixel& newPixel)
{
    if (radius % 2 == 0) {
        for(int brushX = 0; brushX <= radius; brushX++) {
            for(int brushY = 0; brushY <= radius; brushY++) {
                int px = x + brushX/2;
                int py = y + brushY/2;

                // Bounds check
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    addPixel(px, py, newPixel);
                }
            }
        }
    }
    else {
        for(int brushX = -radius/2; brushX <= radius/2; brushX++) {
            for(int brushY = -radius/2; brushY <= radius/2; brushY++) {
                int px = x + brushX;
                int py = y + brushY;

                // Bounds check
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    addPixel(px, py, newPixel);
                }
            }
        }
    }
}

void Sprite::eraseAt(int x, int y, int radius)
{
    if (radius % 2 == 0) {
        for(int brushX = 0; brushX <= radius; brushX++) {
            for(int brushY = 0; brushY <= radius; brushY++) {
                int px = x + brushX/2;
                int py = y + brushY/2;

                // Bounds check
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    removePixelAt(px, py);
                }
            }
        }
    }
    else {
        for(int brushX = -radius/2; brushX <= radius/2; brushX++) {
            for(int brushY = -radius/2; brushY <= radius/2; brushY++) {
                int px = x + brushX;
                int py = y + brushY;

                // Bounds check
                if (px >= 0 && px < width && py >= 0 && py < height) {
                    removePixelAt(px, py);
                }
            }
        }
    }
}
// - Checked by ...
