#include "controller.h"
#include <brush.h>

Controller::Controller(QObject *parent, Spritesheet *_currentSheet) : QObject{parent}, currentFrame(0), currentSheet(_currentSheet) {}

void Controller::switchSprite(int spriteID){
    if (spriteID != currentFrame){
        currentFrame = spriteID;
    }
}

void Controller::toggleDrawing(bool active){
    isDrawing = active;
}

// - Checked by Roland Guerriere
