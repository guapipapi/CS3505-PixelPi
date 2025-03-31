#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>
#include <fileDialog.h>
#include <newcolordialog.h>
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
    void updateSpriteWidget(Sprite *newSprite);
    void updateCurrentPixel(const Pixel &pixel);

private slots:
    void on_FileButton_clicked();
    void on_primary_color_button_clicked();
    void on_secondary_color_button_clicked();

    void on_brushRadiusSpinBox_valueChanged(int arg1);

    void on_showHelpButton_clicked();

    void setNewSpriteDimensions(int x, int y);

public:
    PixelPi(QWidget *parent = nullptr);
    ~PixelPi();
    void keyPressEvent(QKeyEvent *event);
    void showHelpPage();

private:
    Ui::PixelPi *ui;
    FileDialog fileDialog;
    HelpDialog helpDialog;
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
    void mousePaintedAt(int x, int y);
    void newBrushRadius(int newRadius);
};
#endif // PIXELPI_H
