#include "controller.h"
#include <brush.h>

Controller::Controller(QObject *parent, Spritesheet *_currentSheet)
    : QObject{parent}, selectedTool(0), currentFrame(0), currentSheet(_currentSheet)
{}


// int selectedTool;
// bool isDrawing = false;
// int currentFrame;

/**
 * @brief eyeDropper
 * This method takes in an x and y value to find the pixel from the
 * sprite and assign its current color
 *
 * @param x - the x coordinate
 * @param y - the y coordinate
 */
// void Controller::eyeDropper(int x, int y){

//     // find the current sprite through the spritesheet
//     Sprite& spritePtr = currentSheet->getCurrentSprite();

//     // get the color at the current pixel of specified sprite
//     Pixel* newColor = spritePtr.getPixelAt(x, y);

//     // change the color to the new one
//    // emit changeColor(*newColor);
// }

/**
 * @brief zoomed
 * This method handles the event of the user zooming
 */
void Controller::zoomed(){
    // possible parameter needed

    // when user scrolls up its positive
    // use scrolls down negative
}

/**
 * @brief Controller::switchSprite
 * This method will switch the sprite to the current frame
 *
 * @param spriteID - the sprite the frame will be switched to
 */
void Controller::switchSprite(int spriteID){
    if (spriteID != currentFrame){
        currentFrame = spriteID;
    }
    //spriteUpdated();
}

/**
 * @brief setTool
 * This method will set the current tool to the newly selected one
 *
 * @param newTool - the tool it will be set to
 */
void Controller::setTool(int newTool){
    selectedTool = newTool;
}

/**
 * @brief toggleDrawing
 * This method checks if the mouse button is held down
 *
 * @param active - boolean value to tell if user is currently drawing
 */
void Controller::toggleDrawing(bool active){
    isDrawing = active;
}

void Controller::paintedAt(int x, int y, Sprite* sprite, Brush* brush){
    int r = brush->getRadius();

    for(int brushX = -r/2; brushX <= r/2; brushX++) {
        for(int brushY = -r/2; brushY <= r/2; brushY++) {
            int px = x + brushX;
            int py = y + brushY;

            // Bounds check
            if (px >= 0 && px < sprite->width && py >= 0 && py < sprite->height) {
                sprite->addPixel(px, py, *pixel);
            }
        }
    }
}
