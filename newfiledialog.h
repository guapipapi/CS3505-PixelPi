/**
 * @authors: Carlos Alatorre
 *
 * The NewFileDialog class provides a dialog interface for creating a new file.
 * It collects the file dimensions from the user and emits a signal to create the file.
 */
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
    /**
     * Constructor for the NewFileDialog.
     * @param parent - Pointer to the parent widget, default is nullptr.
     */
    explicit NewFileDialog(QWidget *parent = nullptr);

    /**
     * Destructor for the NewFileDialog.
     */
    ~NewFileDialog();

private slots:
    /**
     * Slot triggered when the dialog's button box is accepted.
     * Processes user input and emits a signal to create a new file with specified dimensions.
     */
    void on_buttonBox_accepted();

private:
    /**
     * Pointer to the UI components of the NewFileDialog.
     */
    Ui::NewFileDialog *ui;

signals:
    /**
     * Signal emitted to create a new file.
     * @param width - The width of the new file.
     * @param height - The height of the new file.
     */
    void createNewFile(int width, int height);
};

#endif // NEWFILEDIALOG_H

// - Checked by Imran Khalil
