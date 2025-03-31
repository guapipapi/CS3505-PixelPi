#include "fileDialog.h"
#include "ui_fileDialog.h"
#include <QFileDialog>
#include <qstring.h>

FileDialog::FileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FileDialog) {
    ui->setupUi(this);

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
    saveDirectory = QFileDialog::getExistingDirectory(this);
}


void FileDialog::on_loadButton_clicked()
{
    loadFile = QFileDialog::getOpenFileName(this);
}

