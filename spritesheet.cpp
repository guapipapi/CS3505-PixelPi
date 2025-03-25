#include "spritesheet.h"

Spritesheet::Spritesheet(QObject *parent)
    : QObject{parent}
{}

bool Spritesheet::saveToJson() {

    //JSON code needed here xdd

    return false;
}

bool Spritesheet::loadJson() {

    //JSON code needed here xdd

    return false;
}

bool Spritesheet::exportToPNG() {

    //PNG library needed here l0l

    return false;
}

Sprite Spritesheet::getCurrentSprite() {
    return sprites[currentFrame];
}
