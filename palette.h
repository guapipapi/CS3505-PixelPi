#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <pixel.h>
#include <vector>

class Palette : public QObject
{
    Q_OBJECT
public:
    explicit Palette(QObject *parent = nullptr);
    void setNewCurrentColor();
    void switchToSecondaryColor();
    std::vector<Pixel> getColors();
    void addColor(Pixel newColor);
    void removeColor(Pixel colorToRemove);

private:
    Pixel currentColor;
    Pixel secondaryColor;
    std::vector<Pixel> colors;

signals:
};

#endif // PALETTE_H
