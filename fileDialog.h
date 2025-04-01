/**
 * @author Carlos Alatorre
 *
 * A class for the file dialog that handels loading, saving, and writing new files to disk
 */
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
    /**
     * The constructor for the file dialog
     *
     * @param parent - the QObject for the file dialog to work on
     */
    explicit FileDialog(QWidget *parent = nullptr);

    /**
     * Destructor for the file dialog
     *
     */
    ~FileDialog();

private slots:
    /**
     * Slot for handeling the press event of the new button that will make a new project
     */
    void on_newButton_clicked();

    /**
     * Slot for handeling the press event of the save as button which will write a new file to disk
     */
    void on_saveAsButton_clicked();

    /**
     * Slot for handeling the load button which will load a .ssp file to the program
     */
    void on_loadButton_clicked();

private:
    Ui::FileDialog *ui;
    NewFileDialog newFileDialog;

    QString loadFile;
    QString saveDirectory;
signals:
    /**
     * Makes a new project
     *
     * @param width - the width of the sprite
     * @param height - the height of the sprite
     */
    void createNewFileSignal(int width, int height);

    /**
     * Loads a file from disk into the program
     *
     * @param file - the file path
     */
    void loadFileSignal(QString& file);

    /**
     * Saves the project to an .ssp file
     *
     * @param file - the file path
     */
    void saveFileSignal(QString& file);
};

#endif // FILEDIALOG_H

// - Checked by Roland Guerriere
