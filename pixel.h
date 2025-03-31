#ifndef PIXEL_H
#define PIXEL_H

#include <QVector4D>
#include <QJsonObject>

class Pixel {

    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

    public:

        Pixel() { r = 0; g = 0; b= 0; a = 0; }
        Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

        //Convert pixel data to JSON
        QJsonObject toJson() const {
            QJsonObject jsonObj;
            jsonObj["r"] = r;
            jsonObj["g"] = g;
            jsonObj["b"] = b;
            jsonObj["a"] = a;
            return jsonObj;
        }

        void fromJson(const QJsonObject& jsonObj) {
            r = jsonObj["r"].toInt();
            g = jsonObj["g"].toInt();
            b = jsonObj["b"].toInt();
            a = jsonObj["a"].toInt();
        }

        unsigned char getRedValue();
        unsigned char getGreenValue();
        unsigned char getBlueValue();
        unsigned char getAlphaValue();

        void setRedValue(unsigned char r);
        void setGreenValue(unsigned char g);
        void setBlueValue(unsigned char b);
        void setAlphaValue(unsigned char a);
        QVector4D getRGBA();
};

#endif // PIXEL_H
