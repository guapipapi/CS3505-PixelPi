#include "spritesheet.h"

/*
public:
    explicit Spritesheet(QObject *parent = nullptr);
    // Returns true if operation was a success
    bool saveToJson();
    // Returns true if operation was a success
    bool loadJson();
    // You know
    bool exportToPNG();
    // Returns the current sprite
    Sprite getCurrentSprite();
private:
    int width;
    int height;
    std::string projectName;

    int currentFrame;


    Timeline timeline;
    std::vector<Sprite> sprites;
 *
 *
*/


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
