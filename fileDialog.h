#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <newfiledialog.h>

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();

private slots:
    void on_newButton_clicked();
// void createNewFile(int width, int height);

private:
    Ui::FileDialog *ui;
    NewFileDialog newFileDialog;
signals:
    void createNewFileSignal(int width, int height);
};

#endif // FILEDIALOG_H
