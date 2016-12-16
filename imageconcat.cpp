#include "imageconcat.h"
#include "ui_imageconcat.h"
#include "resmanager.h"

#include <iostream>
#include <string>
#include <QMessageBox>
#include <QFileDialog>
#include <QGroupBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QString>
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

void ImageConcat::createCheckGroup(int count) {
    QGroupBox * groupbox = ui->checkGroup;
    groupbox->setFlat(true);
    QVBoxLayout *vbox = new QVBoxLayout;
    for (int i = 0; i < count; ++i) {
        QCheckBox *check = new QCheckBox(QString::fromStdString(std::to_string(i+1)));
        vbox->addWidget(check);
        _check_group.push_back(check);
    }
    vbox->addStretch(1);
    groupbox->setLayout(vbox);
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
        // display the options according to the layer counts
        const int layer_count = jqh::ResManager::getInstance()->getLayerCount();
        // add checkbox to the option
        createCheckGroup(layer_count);

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




