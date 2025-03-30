#include "fileDialog.h"
#include "ui_fileDialog.h"

FileDialog::FileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FileDialog)
{
    ui->setupUi(this);

    QObject::connect(&newFileDialog, &NewFileDialog::createNewFile, this, &FileDialog::createNewFileSignal);
}

FileDialog::~FileDialog()
{
    delete ui;
}

void FileDialog::on_newButton_clicked()
{
    newFileDialog.show();
    newFileDialog.setModal(true);
}

