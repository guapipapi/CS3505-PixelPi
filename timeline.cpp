#include "timeline.h"
#include "QTimer"

Timeline::Timeline(QObject *parent) : QObject{parent}, framesPerSecond(1), timer(new QTimer(this)) {
    QObject::connect(&timer, &QTimer::timeout, this, &Timeline::switchSprite);
}

void Timeline::changeFPS(int newFPS) {
    framesPerSecond = newFPS;
    if (timer.isActive()) {
        timer.start(1000 / framesPerSecond);
    }
}

void Timeline::playAnimation() {
    playing = !playing;

    emit isPlayingAnimation(playing);

    if (playing) {
        timer.start(1000 / framesPerSecond);
    } else {
        timer.stop();
    }
}

void Timeline::switchSprite() {
    emit goToNextSprite();
}

void Timeline::stopAnimation() {
    timer.stop();
    emit isPlayingAnimation(false);
}

// - Checked by Roland Guerriere
