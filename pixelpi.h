#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>
#include <fileDialog.h>
#include <QKeyEvent>
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
    void updateCurrentPixel(const Pixel& pixel);

private slots:
    void on_FileButton_clicked();
    void on_primary_color_button_clicked();
    void on_secondary_color_button_clicked();

public:
    PixelPi(QWidget *parent = nullptr);
    ~PixelPi();
    void keyPressEvent(QKeyEvent *event);


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
    void changePrimaryColor(Pixel pixel);
    void changeSecondaryColor(Pixel pixel);
    void switchColors();


};
#endif // PIXELPI_H
