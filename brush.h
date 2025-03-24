#ifndef BRUSH_H
#define BRUSH_H

#include <QObject>

class Brush : public QObject
{
    Q_OBJECT
public:
    explicit Brush(QObject *parent = nullptr);
    int getRadius();
    void increaseRadius();
    void decreaseRadius();
private:
    int radius;

signals:
};

#endif // BRUSH_H
