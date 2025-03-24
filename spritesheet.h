#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QObject>
#include <timeline.h>
#include <sprite.h>>
#include <vector>
#include <string>

class Spritesheet : public QObject
{
    Q_OBJECT
public:
    explicit Spritesheet(QObject *parent = nullptr);
    // Returns true if operation was a success
    bool SaveToJson();
    // Returns true if operation was a success
    bool LoadJson();
    // You know
    bool ExportToPNG();
    // Returns the current sprite
    Sprite GetCurrentSprite();
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
