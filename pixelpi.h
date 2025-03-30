#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>
#include <fileDialog.h>
#include <newcolordialog.h>
#include <sprite.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class PixelPi;
}
QT_END_NAMESPACE

class PixelPi : public QMainWindow
{
    Q_OBJECT

public slots:
    // void drawCanvas();
    // void zoomTo(int x, int y, int magnitude);
    void updateSpriteWidget(Sprite *newSprite);

private slots:
    void on_FileButton_clicked();

    void on_brushRadiusSpinBox_valueChanged(int arg1);

public:
    PixelPi(QWidget *parent = nullptr);
    ~PixelPi();

private:
    Ui::PixelPi *ui;
    FileDialog fileDialog;



    int zoomLevel;
    int zoomX;
    int zoomY;

    void increaseZoom();
    void dragZoom(int newX, int newY);
    void resetZoom();
signals:
    void createNewFile(int width, int height);
    void mousePaintedAt(int x, int y);
    void newBrushRadius(int newRadius);


};
#endif // PIXELPI_H
