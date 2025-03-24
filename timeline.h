#ifndef TIMELINE_H
#define TIMELINE_H

#include <QObject>

class Timeline : public QObject
{
    Q_OBJECT
public:
    explicit Timeline(QObject *parent = nullptr);
    void PlayAnimation();
    void ChangeFPS(int newFPS);
    void DeleteSprite(int spriteID);
    void AddSprite();
    void SwitchSprite();


private:
    int framesPerSecond;

signals:
};

#endif // TIMELINE_H
