#include "timeline.h"

Timeline::Timeline(QObject *parent)
    : QObject{parent}
{}

void Timeline::changeFPS(int newFPS){
    framesPerSecond = newFPS;
}

void Timeline::deleteSprite(){

}

void Timeline::playAnimation(){
    playing = !playing;

    if (playing)
    {

    }
}

void Timeline::addSprite(){

}

void Timeline::switchSprite(){

}
