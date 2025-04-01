/**
 * @authors: Carlos Alatorre, Imrand Khalil, Scott Ceja, Roland Guerriere
 *
 * The PixelPi class represents the main application window for the sprite editor.
 * It handles user interactions such as file operations, color selection, zoom management,
 * sprite navigation, and animation control.
 */
#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>
#include <fileDialog.h>
#include <helpdialog.h>
#include <QKeyEvent>
#include <sprite.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class PixelPi;
}
QT_END_NAMESPACE

class PixelPi : public QMainWindow
{
    Q_OBJECT

public slots:
    /**
     * Updates the sprite widget with new sprite data.
     * @param newSprite - Pointer to the new Sprite object to be displayed.
     */
    void updateSpriteWidget(Sprite *newSprite);

    /**
     * Updates the currently selected pixel.
     * @param pixel - Reference to the new Pixel data.
     */
    void updateCurrentPixel(const Pixel &pixel);

    /**
     * Updates the index of the current sprite being displayed.
     * @param currentSprite - The index of the current sprite.
     */
    void updateCurrentSprite(int currentSprite);

    /**
     * Sets new dimensions for the sprite canvas.
     * @param x - New width for the sprite.
     * @param y - New height for the sprite.
     */
    void setNewSpriteDimensions(int x, int y);

    /**
     * Enables or disables the play button.
     * @param canPlay - Boolean flag indicating if the play button should be enabled.
     */
    void enablePlayButton(bool canPlay);

    /**
     * Updates the interface to reflect whether an animation is playing.
     * @param isPlaying - Boolean flag indicating animation status.
     */
    void isPlayingAnimation(bool isPlaying);

    /**
     * Enables or disables the next sprite navigation button.
     * @param enable - Boolean flag to enable or disable the button.
     */
    void nextSpriteEnable(bool enable);

    /**
     * Enables or disables the previous sprite navigation button.
     * @param enable - Boolean flag to enable or disable the button.
     */
    void previousSpriteEnable(bool enable);

private slots:
    /**
     * Slot triggered when the File button is clicked.
     */
    void on_FileButton_clicked();

    /**
     * Slot triggered when the primary color button is clicked.
     */
    void on_primary_color_button_clicked();

    /**
     * Slot triggered when the secondary color button is clicked.
     */
    void on_secondary_color_button_clicked();

    /**
     * Slot triggered when the brush radius spin box value is changed.
     * @param arg1 - The new brush radius value.
     */
    void on_brushRadiusSpinBox_valueChanged(int arg1);

    /**
     * Slot triggered when the Help button is clicked.
     */
    void on_showHelpButton_clicked();

    /**
     * Slot triggered when the FPS spin box value is changed.
     * @param arg1 - The new frames per second value.
     */
    void on_fpsSpinBox_valueChanged(int arg1);

    /**
     * Slot triggered when the Play Animation button is clicked.
     */
    void on_playAnimationButton_clicked();

    /**
     * Slot triggered when the Add Sprite button is clicked.
     */
    void on_addSpriteButton_clicked();

    /**
     * Slot triggered when the Remove Sprite button is clicked.
     */
    void on_removeSpriteButton_clicked();

    /**
     * Slot triggered when the Previous Sprite button is clicked.
     */
    void on_previousSpriteButton_clicked();

    /**
     * Slot triggered when the Next Sprite button is clicked.
     */
    void on_nextSpriteButton_clicked();

public:
    /**
     * Constructor for the PixelPi main window.
     * @param parent - Pointer to the parent widget, default is nullptr.
     */
    PixelPi(QWidget *parent = nullptr);

    /**
     * Destructor for the PixelPi class.
     */
    ~PixelPi();

    /**
     * Handles key press events.
     * @param event - Pointer to the QKeyEvent containing event data.
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * Displays the help page dialog.
     */
    void showHelpPage();

private:
    /**
     * Pointer to the UI elements of the PixelPi window.
     */
    Ui::PixelPi *ui;

    /**
     * Instance of FileDialog for managing file operations.
     */
    FileDialog fileDialog;

    /**
     * Instance of HelpDialog for displaying help information.
     */
    HelpDialog helpDialog;

    /**
     * Zoom level for the sprite view.
     */
    int zoomLevel;

    /**
     * X-coordinate for zooming.
     */
    int zoomX;

    /**
     * Y-coordinate for zooming.
     */
    int zoomY;

    /**
     * Increases the zoom level of the sprite view.
     */
    void increaseZoom();

    /**
     * Adjusts the zoom view based on new X and Y coordinates.
     * @param newX - New X coordinate for zoom adjustment.
     * @param newY - New Y coordinate for zoom adjustment.
     */
    void dragZoom(int newX, int newY);

    /**
     * Resets the zoom settings to the default state.
     */
    void resetZoom();

signals:
    /**
     * Signal to create a new file with specified dimensions.
     * @param width - Width for the new file.
     * @param height - Height for the new file.
     */
    void createNewFile(int width, int height);

    /**
     * Signal to change the primary color.
     * @param pixel - New Pixel data representing the primary color.
     */
    void changePrimaryColor(Pixel pixel);

    /**
     * Signal to change the secondary color.
     * @param pixel - New Pixel data representing the secondary color.
     */
    void changeSecondaryColor(Pixel pixel);

    /**
     * Signal to swap the primary and secondary colors.
     */
    void switchColors();

    /**
     * Signal emitted when the mouse paints at a specific coordinate.
     * @param x - X coordinate where painting occurred.
     * @param y - Y coordinate where painting occurred.
     */
    void mousePaintedAt(int x, int y);

    /**
     * Signal emitted when the mouse erases at a specific coordinate.
     * @param x - X coordinate where erasing occurred.
     * @param y - Y coordinate where erasing occurred.
     */
    void mouseErasedAt(int x, int y);

    /**
     * Signal to update the brush radius.
     * @param newRadius - The new brush radius.
     */
    void newBrushRadius(int newRadius);

    /**
     * Signal to load a file.
     * @param file - File path of the file to be loaded.
     */
    void loadFile(QString &file);

    /**
     * Signal to save a file.
     * @param file - File path where the file will be saved.
     */
    void saveFile(QString &file);

    /**
     * Signal to set a new frames per second value for the animation.
     * @param newFramesPerSecond - The new FPS value.
     */
    void newFPS(int newFramesPerSecond);

    /**
     * Signal to trigger playing the animation.
     */
    void playAnimation();

    /**
     * Signal to add a new sprite.
     */
    void addSprite();

    /**
     * Signal to remove an existing sprite.
     */
    void removeSprite();

    /**
     * Signal to switch to the next sprite.
     */
    void goToNextSprite();

    /**
     * Signal to switch to the previous sprite.
     */
    void goToPreviousSprite();
};

#endif // PIXELPI_H
// - Checked by Imran Khalil
