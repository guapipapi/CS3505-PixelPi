#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void EyeDropper(int x, int y);
    void Zoomed();
    void SwitchSprite(int spriteID);
    void setTool(int newTool);


public slots:
    void PaintedAt(int x, int y);
    void SpriteUpdated();
private:
    int selectedTool;
    bool isDrawing;
    int currentFrame;

    void toggleDrawing(bool active);



signals:
};

#endif // CONTROLLER_H
