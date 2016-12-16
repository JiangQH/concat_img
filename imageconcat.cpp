#include "imageconcat.h"
#include "ui_imageconcat.h"
#include "resmanager.h"

#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
ImageConcat::ImageConcat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageConcat)
{
    ui->setupUi(this);

    // connect the signal and slots
    connectSignalAndSlots();
}



void ImageConcat::connectSignalAndSlots() {
    //this is the signal function, used to connect
    // all the slot and signals

    // the browseButton
    connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(onBrowseFiles()));
    // the saveButton
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(onSaveData()));
    // the check button? how to set it automatically?
}






ImageConcat::~ImageConcat()
{
    delete ui;
}

void ImageConcat::onBrowseFiles()
{
    std::cout << "Browse clicked" << std::endl;
    QString path = QFileDialog::getExistingDirectory(this, "Open the depth layer folder", QString(),
                                                     QFileDialog::ShowDirsOnly);
    if (!path.isEmpty()) {
        // for debug
        std::cout << "opened layer depth dir" << path.toStdString() << std::endl;
        // load data
        jqh::ResManager::getInstance()->loadLayers(path.toStdString());
    }
}

void ImageConcat::onSaveData()
{
    // save data
    std::cout << "on save clicked" << std::endl;
}

void ImageConcat::onCheckStateChanged(int arg1)
{

}


