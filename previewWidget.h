#ifndef PREVIEWWIDGET_H
#define PREVIEWWIDGET_H

#include <QWidget>
#include <QPainter>

#include <QMouseEvent>
#include "sprite.h"

class PreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWidget(QWidget *parent);
    void setSprite(Sprite* newSprite);
    void draw();

private:
    Sprite* sprite = nullptr;

protected:
    void paintEvent(QPaintEvent* event) override;

};

#endif // PREVIEWWIDGET_H
