#include "fileDialog.h"
#include "ui_fileDialog.h"
#include <QFileDialog>
#include <qstring.h>

FileDialog::FileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FileDialog) {
    ui->setupUi(this);

    // Connects the new file button to the new file signal
    QObject::connect(&newFileDialog, &NewFileDialog::createNewFile, this, &FileDialog::createNewFileSignal);
}

FileDialog::~FileDialog() {
    delete ui;
}

void FileDialog::on_newButton_clicked() {
    newFileDialog.show();
    newFileDialog.setModal(true);
}

void FileDialog::on_saveAsButton_clicked()
{
    saveDirectory = QFileDialog::getSaveFileName(this, "Save File", saveDirectory + "/default_filename.ssp", "Text Files (*.ssp);;All Files (*)");

    if (!saveDirectory.isEmpty()) {
        emit saveFileSignal(saveDirectory);
    }

}


void FileDialog::on_loadButton_clicked()
{
    loadFile = QFileDialog::getOpenFileName(this);

    if (!loadFile.isEmpty()) {
        emit loadFileSignal(loadFile);
    }
}

// - Checked by Roland Guerriere
