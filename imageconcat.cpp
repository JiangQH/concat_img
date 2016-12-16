#include "imageconcat.h"
#include "ui_imageconcat.h"

ImageConcat::ImageConcat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageConcat)
{
    ui->setupUi(this);
}

ImageConcat::~ImageConcat()
{
    delete ui;
}
