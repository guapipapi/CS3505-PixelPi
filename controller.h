#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void eyeDropper(int x, int y);
    void zoomed();
    void switchSprite(int spriteID);
    void setTool(int newTool);


public slots:
    // void paintedAt(int x, int y);
    // void spriteUpdated();
private:
    int selectedTool;
    bool isDrawing;
    int currentFrame;

    void toggleDrawing(bool active);



signals:
};

#endif // CONTROLLER_H
