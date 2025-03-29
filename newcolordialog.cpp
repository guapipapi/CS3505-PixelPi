#include "newcolordialog.h"
#include "ui_newcolordialog.h"

NewColorDialog::NewColorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewColorDialog)
{
    ui->setupUi(this);
}

NewColorDialog::~NewColorDialog()
{
    delete ui;
}
