#include "timeline.h"
#include "QTimer"
#include <iostream>

Timeline::Timeline(QObject *parent)
    : QObject{parent}, timer(new QTimer(this))
{
    QObject::connect(&timer, &QTimer::timeout, this, &Timeline::switchSprite);
}

void Timeline::changeFPS(int newFPS){
    framesPerSecond = newFPS;
    if (timer.isActive()) {
        timer.start(1000 / framesPerSecond);  // Restart timer with new FPS
    }
}

void Timeline::deleteSprite(){

}

void Timeline::playAnimation(){
    playing = !playing;

    if (playing) {
        timer.start(1000 / framesPerSecond); // Start repeating timer
    } else {
        timer.stop();
    }
}

void Timeline::addSprite(){

}

void Timeline::switchSprite(){
    std::cout << "sprite switched" << std::endl;
}
