#include "ui_manager.h"
#include "res_manager.h"
#include <iostream>
#include <QFileDialog>
#include <QString>
#include <QGroupBox>
#include <QVBoxLayout>
namespace jqh {


UiManager::UiManager()
{
    // nothing here
    _vbox_layout = new QVBoxLayout;
}

UiManager::~UiManager() {
    // currently nothing

}

UiManager* UiManager::getInstance() {
    static UiManager instance;
    return &instance;
}

void UiManager::run() {
    _main_window.show();
}

void UiManager::receiveSignal(Signal s) {
    // receive the signal, judge who send?

    switch (s._sender) {
    case browse:
        std::cout << "browse clicked" << std::endl;
        // browseFiles
        browseFile();
        // update the checkbox
        updateCheckBox();
        break;
    case save:
        //do something
        break;
    case checked:
        // check first
        std::cout << "checked" << s._id << std::endl;
        break;
    case unchecked:
        std::cout << "unchecked" << s._id << std::endl;
        break;

    }
}

void UiManager::browseFile() {
    // browse the folder
    QString path = QFileDialog::getExistingDirectory(&_main_window, "Open the depth layer folder", QString(),
                                                         QFileDialog::ShowDirsOnly);
    if (!path.isEmpty()) {
        // load layers
        if (!ResManager::getInstance()->loadLayers(path.toStdString())) {
            // load failed
            std::cout << "load file failed" << std::endl;
        }
    }
}

void UiManager::updateCheckBox() {
    // create checkbox according to the layer_count
    const int layer_count = ResManager::getInstance()->getLayerCount();
    for (int i = 0; i < layer_count; ++i) {
        UIImgCheck *check = new UIImgCheck(i);
        _vbox_layout->addWidget(check);
        _check_group.push_back(check);
    }
    _vbox_layout->addStretch(1);
    // set the layout in mainwindow
    _main_window.setGropubox(_vbox_layout);
}

}// end of namespace
