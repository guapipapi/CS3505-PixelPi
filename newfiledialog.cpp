#include "newfiledialog.h"
#include "ui_newfiledialog.h"

NewFileDialog::NewFileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

void NewFileDialog::on_buttonBox_accepted()
{
    // CREATE NEW FILE
    emit createNewFile(ui->widthSpinBox->value(), ui->heightSpinBox->value());
}

