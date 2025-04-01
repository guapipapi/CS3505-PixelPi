/**
 * @authors: Carlos Alatorre
 *
 * The Pixel class represents a single pixel with RGBA color properties.
 * It provides functionality to convert pixel data to and from JSON, and methods
 * to get and set individual color channel values.
 */
#ifndef PIXEL_H
#define PIXEL_H

#include <QVector4D>
#include <QJsonObject>

class Pixel {

private:
    /**
         * Red color channel value.
         */
    unsigned char r;

    /**
         * Green color channel value.
         */
    unsigned char g;

    /**
         * Blue color channel value.
         */
    unsigned char b;

    /**
         * Alpha (transparency) channel value.
         */
    unsigned char a;

public:
    /**
         * Default constructor for the Pixel class.
         * Initializes all color channels (r, g, b, a) to 0.
         */
    Pixel() { r = 0; g = 0; b = 0; a = 0; }

    /**
         * Parameterized constructor for the Pixel class.
         * @param red - Red channel value.
         * @param green - Green channel value.
         * @param blue - Blue channel value.
         * @param alpha - Alpha (transparency) value.
         */
    Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

    /**
         * Converts the pixel data to a QJsonObject.
         * @return QJsonObject containing the pixel's color data.
         */
    QJsonObject toJson() const {
        QJsonObject jsonObj;
        jsonObj["r"] = r;
        jsonObj["g"] = g;
        jsonObj["b"] = b;
        jsonObj["a"] = a;
        return jsonObj;
    }

    /**
         * Loads pixel data from a QJsonObject.
         * @param jsonObj - QJsonObject containing pixel color data.
         */
    void fromJson(const QJsonObject& jsonObj) {
        r = jsonObj["r"].toInt();
        g = jsonObj["g"].toInt();
        b = jsonObj["b"].toInt();
        a = jsonObj["a"].toInt();
    }

    /**
         * Gets the red channel value of the pixel.
         * @return Red channel value.
         */
    unsigned char getRedValue();

    /**
         * Gets the green channel value of the pixel.
         * @return Green channel value.
         */
    unsigned char getGreenValue();

    /**
         * Gets the blue channel value of the pixel.
         * @return Blue channel value.
         */
    unsigned char getBlueValue();

    /**
         * Gets the alpha channel value of the pixel.
         * @return Alpha channel value.
         */
    unsigned char getAlphaValue();

    /**
         * Sets the red channel value of the pixel.
         * @param r - New red channel value.
         */
    void setRedValue(unsigned char r);

    /**
         * Sets the green channel value of the pixel.
         * @param g - New green channel value.
         */
    void setGreenValue(unsigned char g);

    /**
         * Sets the blue channel value of the pixel.
         * @param b - New blue channel value.
         */
    void setBlueValue(unsigned char b);

    /**
         * Sets the alpha channel value of the pixel.
         * @param a - New alpha channel value.
         */
    void setAlphaValue(unsigned char a);

    /**
         * Retrieves the pixel's RGBA values as a QVector4D.
         * @return QVector4D representing the pixel's RGBA values.
         */
    QVector4D getRGBA();
};

#endif // PIXEL_H

// - Checked by Imran Khalil
