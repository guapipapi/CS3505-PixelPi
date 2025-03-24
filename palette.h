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
    void SetNewCurrentColor();
    void SwitchToSecondaryColor();
    std::vector<Pixel> GetColors();
    void AddColor(Pixel newColor);
    void RemoveColor(Pixel colorToRemove);

private:
    Pixel currentColor;
    Pixel secondaryColor;
    std::vector<Pixel> colors;

signals:
};

#endif // PALETTE_H
