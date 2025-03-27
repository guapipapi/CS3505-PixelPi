#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QObject>
#include <timeline.h>
#include <sprite.h>
#include <vector>
#include <string>
#include <QJsonArray>

class Spritesheet : public QObject
{
    Q_OBJECT
public:
    explicit Spritesheet(QObject *parent = nullptr);
    // Returns true if operation was a success
    bool saveToJson(QString& filePath);
    // Returns true if operation was a success
    bool loadJson(QString& filePath);
    // You know
    bool exportToPNG();
    // Returns the current sprite
    Sprite getCurrentSprite();

    //Convert sprite sheet to JSON
    QJsonObject toJson() const {
        QJsonObject jsonObj;
        jsonObj["projectName"] = QString::fromStdString(projectName);
        jsonObj["width"] = width;
        jsonObj["height"] = height;
        jsonObj["currentFrame"] = currentFrame;

        //Put all sprites into the JSON array
        QJsonArray spriteArray;
        for (const auto& sprite : sprites) {
            spriteArray.append(sprite.toJson());
        }
        jsonObj["sprites"] = spriteArray;

        return jsonObj;
    }

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
