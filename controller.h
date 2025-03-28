#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "pixel.h"
#include "spritesheet.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, Spritesheet *_currentSheet = nullptr);

    void eyeDropper(int x, int y);
    void zoomed();
    void switchSprite(int spriteID);
    void setTool(int newTool);


public slots:
    // void paintedAt(int x, int y);
   // void spriteUpdated();

private:
    int selectedTool;
    bool isDrawing = false;
    int currentFrame;

    void toggleDrawing(bool active);

    Spritesheet* currentSheet;


signals:
    void changeColor(Pixel newColor);
};

#endif // CONTROLLER_H
