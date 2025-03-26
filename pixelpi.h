#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>
#include <fileDialog.h>
#include <QPainter>
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

private slots:
    // void on_FileButton_clicked();


public:
    PixelPi(QWidget *parent = nullptr);
    ~PixelPi();

private:
    Ui::PixelPi *ui;
    FileDialog fileDialog;


    int zoomLevel;
    int zoomX;
    int zoomY;


};
#endif // PIXELPI_H
