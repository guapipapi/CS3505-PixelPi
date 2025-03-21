#ifndef PIXEL_H
#define PIXEL_H

class Pixel {

    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

    public:

        Pixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
        unsigned char getRedValue();
        unsigned char getGreenValue();
        unsigned char getBlueValue();
        unsigned char getAlphaValue();
};

#endif // PIXEL_H
