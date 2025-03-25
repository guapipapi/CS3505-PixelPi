#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QObject>
#include <timeline.h>
#include <sprite.h>
#include <vector>
#include <string>

class Spritesheet : public QObject
{
    Q_OBJECT
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

signals:
};

#endif // SPRITESHEET_H
