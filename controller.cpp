#include "controller.h"
#include <brush.h>

Controller::Controller(QObject *parent, Spritesheet *_currentSheet)
    : QObject{parent}, selectedTool(0), currentFrame(0), currentSheet(_currentSheet)
{}

void Controller::switchSprite(int spriteID){
    if (spriteID != currentFrame){
        currentFrame = spriteID;
    }
}

void Controller::setTool(int newTool){
    selectedTool = newTool;
}

void Controller::toggleDrawing(bool active){
    isDrawing = active;
}
