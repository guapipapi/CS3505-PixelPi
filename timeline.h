    #ifndef TIMELINE_H
#define TIMELINE_H

#include <QObject>
#include <QTimer>

class Timeline : public QObject
{
    Q_OBJECT
public:
    explicit Timeline(QObject *parent = nullptr);

public slots:
    void changeFPS(int newFPS);
    void deleteSprite();
    void playAnimation();
    void addSprite();
    void switchSprite();

private:
    int framesPerSecond;
    bool playing = false;
    QTimer timer;


signals:
};

#endif // TIMELINE_H
