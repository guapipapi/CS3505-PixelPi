#ifndef FILEPOPUP_H
#define FILEPOPUP_H

#include <QWidget>

namespace Ui {
class FilePopup;
}

class FilePopup : public QWidget
{
    Q_OBJECT

public:
    explicit FilePopup(QWidget *parent = nullptr);
    ~FilePopup();

private:
    Ui::FilePopup *ui;
};

#endif // FILEPOPUP_H
