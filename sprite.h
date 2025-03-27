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

    //Convert sprite data to JSON
    QJsonObject toJson() const {
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

    //Load Sprite from JSON
    void fromJson(const QJsonObject& jsonObj) {
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

signals:
    void spriteUpdated();
private:
    std::map<std::pair<int, int>, Pixel> backing;
};

#endif // SPRITE_H
