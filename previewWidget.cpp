#include "previewWidget.h"
#include "pixel.h"

#include <QWidget>

PreviewWidget::PreviewWidget(QWidget *parent) : QWidget{parent} {
    setMouseTracking(true);
}

void PreviewWidget::setSprite(Sprite *newSprite) {
    this->sprite = newSprite;
}

void PreviewWidget::draw(){
    update();
}

void PreviewWidget::paintEvent(QPaintEvent *){

    if (sprite == nullptr)
        return;

    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    int pixelSize = qMax(1, (this->width() / sprite->width));

    for(int x = 0; x < sprite->width; x++) {
        for(int y = 0; y < sprite->height; y++) {
            if(sprite->getPixelAt(x, y) != nullptr) {
                Pixel* p = sprite->getPixelAt(x, y);
                painter.setBrush(QColor(p->getRedValue(), p->getGreenValue(), p->getBlueValue(), p->getAlphaValue()));

                QRect rect(x*pixelSize, y*pixelSize, pixelSize, pixelSize);
                painter.drawRect(rect);
            }
        }
    }
}
