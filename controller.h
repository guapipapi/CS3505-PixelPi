/**
 * @author Imran Khalil
 *
 * The controller class that controls ther functions for managing sprites, tools, and background functions
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "spritesheet.h"
#include <QMouseEvent>
#include <brush.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    /**
     * @param parent - the QObject for the controller to parent to
     * @param _currentSheet - the spritesheet to be operated on
     */
    explicit Controller(QObject *parent = nullptr, Spritesheet *_currentSheet = nullptr);

    /**
     * This method will switch the sprite to the current frame
     *
     * @param spriteID - the sprite the frame will be switched to
     */
    void switchSprite(int spriteID);

    /**
     * This method will set the current tool to the newly selected one
     *
     * @param newTool - the tool it will be set to
     */
    void setTool(int newTool);

private:
    int selectedTool;
    bool isDrawing = false;
    int currentFrame;

    /**
     * This method checks if the mouse button is held down
     *
     * @param active - boolean value to tell if user is currently drawing
     */
    void toggleDrawing(bool active);

    Spritesheet* currentSheet;
};

#endif // CONTROLLER_H

// - Checked by Roland Guerriere
