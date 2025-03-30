#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>

namespace Ui {
class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(QWidget *parent = nullptr);
    ~NewFileDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewFileDialog *ui;
signals:
    void createNewFile(int width, int height);
};

#endif // NEWFILEDIALOG_H
