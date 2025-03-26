#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        QPen pen(Qt::blue);
        pen.setWidth(10);
        painter.setPen(pen);

        QRect rect(10, 20, 80, 60);
        painter.drawEllipse(rect);
    }
};


#endif // PAINTWIDGET_H
