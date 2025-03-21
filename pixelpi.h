#ifndef PIXELPI_H
#define PIXELPI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class PixelPi;
}
QT_END_NAMESPACE

class PixelPi : public QMainWindow
{
    Q_OBJECT

public:
    PixelPi(QWidget *parent = nullptr);
    ~PixelPi();

private:
    Ui::PixelPi *ui;
};
#endif // PIXELPI_H
