#include "fileDialog.h"
#include "ui_fileDialog.h"

FileDialog::FileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FileDialog)
{
    ui->setupUi(this);
}

FileDialog::~FileDialog()
{
    delete ui;
}
