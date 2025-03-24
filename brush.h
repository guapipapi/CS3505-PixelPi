#ifndef BRUSH_H
#define BRUSH_H

#include <QObject>

class Brush : public QObject
{
    Q_OBJECT
public:
    explicit Brush(QObject *parent = nullptr);
    int GetRadius();
    void IncreaseRadius();
    void DecreaseRadius();
private:
    int radius;

signals:
};

#endif // BRUSH_H
