#include "timeline.h"
#include "QTimer"

Timeline::Timeline(QObject *parent)
    : QObject{parent}, timer(new QTimer(this))
{
    QObject::connect(&timer, &QTimer::timeout, this, &Timeline::switchSprite);
}

void Timeline::changeFPS(int newFPS){
    framesPerSecond = newFPS;
    if (timer.isActive()) {
        timer.start(1000 / framesPerSecond);
    }
}

void Timeline::playAnimation(){
    playing = !playing;

    if (playing) {
        timer.start(1000 / framesPerSecond);
    } else {
        timer.stop();
    }
}

void Timeline::switchSprite(){
    emit goToNextSprite();
}
