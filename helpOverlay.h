#ifndef HELPOVERLAY_H
#define HELPOVERLAY_H

#include <QWidget>

class HelpOverlay : public QWidget {
    Q_OBJECT
public:
    explicit HelpOverlay(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // HELPOVERLAY_H
