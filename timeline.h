/**
 * @author Carlos Alatorre
 *
 * Manages the timeline and handels animations
 */
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
    /**
     * @param newFPS - Sets the new FPS
     */
    void changeFPS(int newFPS);

    /**
     * Plays the animation at the proper fps
     */
    void playAnimation();

    /**
     * Switches the sprite on the canavas
     */
    void switchSprite();

    /**
     * Pauses the animation
     */
    void stopAnimation();

private:
    // The speed at which the animation is played
    int framesPerSecond;
    // A boolean for the keeping track of the if the animation is playing
    bool playing = false;
    // A timer for pausing between frames
    QTimer timer;


signals:
    /**
     * Goes to the next sprite in the timeline
     */
    void goToNextSprite();

    /**
     * Is the animation playing
     * @param isPlaying - A boolean of if the animation is playing
     */
    void isPlayingAnimation(bool isPlaying);
};

#endif // TIMELINE_H

// - Checked by Imran Khalil
