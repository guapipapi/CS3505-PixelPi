#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <newfiledialog.h>
#include <QString>

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

    void on_saveAsButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::FileDialog *ui;
    NewFileDialog newFileDialog;

    QString loadFile;
    QString saveDirectory;
signals:
    void createNewFileSignal(int width, int height);

    void loadFileSignal(QString& file);
    void saveFileSignal(QString& file);
};

#endif // FILEDIALOG_H
