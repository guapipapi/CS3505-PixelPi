#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <pixel.h>
#include "brush.h"

class Palette : public QObject
{
    Q_OBJECT
public:
    explicit Palette(QObject *parent, Brush &brush);

private:
    Pixel currentColor;
    Pixel secondaryColor;
    Brush &brush;

signals:
    void currentColorChanged(const Pixel &pixel);

public slots:
    void setNewCurrentColor(const Pixel &pixel);
    void setNewSecondaryColor(const Pixel &pixel);
    void switchToSecondaryColor();
    const Pixel &getCurrentColor();
};

#endif // PALETTE_H
