#ifndef TIMELINE_H
#define TIMELINE_H

#include <QObject>

class Timeline : public QObject
{
    Q_OBJECT
public:
    explicit Timeline(QObject *parent = nullptr);
    void playAnimation();
    void changeFPS(int newFPS);
    void deleteSprite(int spriteID);
    void addSprite();
    void switchSprite();


private:
    int framesPerSecond;

signals:
};

#endif // TIMELINE_H
