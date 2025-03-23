#include "filepopup.h"
#include "ui_filepopup.h"

FilePopup::FilePopup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilePopup)
{
    ui->setupUi(this);
}

FilePopup::~FilePopup()
{
    delete ui;
}
