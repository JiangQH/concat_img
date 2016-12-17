#include "ui_manager.h"
#include "res_manager.h"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <QString>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QMessageBox>
namespace jqh {

using namespace std;
UiManager::UiManager()
{
    _vbox_layout = new QVBoxLayout;
    _clicked = 0;
   // updateUi();
}

UiManager::~UiManager() {
    // currently nothing
    delete _vbox_layout;
    for (auto item: _check_group) {
        delete item;
    }
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
    {
        //std::cout << "browse clicked" << std::endl;
        // browseFiles
        if(browseFile()) {
            updateUi();
        }
        else {
            message("load layer folder failed");
        }
    }
        break;

    case save:
    {
        //do something
        _clicked += 1;
        string msg = ResManager::getInstance()->saveCurrentImg(_clicked);
        message(msg);
    }
        break;

    case checked:
    {
        // check first
        ResManager::getInstance()->updateCurrentImg(s._id, add);
        updateImgView();
        //std::cout << "checked" << s._id << std::endl;
    }
        break;

    case unchecked:
    {
        ResManager::getInstance()->updateCurrentImg(s._id, sub);
        updateImgView();
        //std::cout << "unchecked" << s._id << std::endl;
    }
        break;

    }
}

bool UiManager::browseFile() {
    // browse the folder
    QString path = QFileDialog::getExistingDirectory(&_main_window, "Open the depth layer folder", QString(),
                                                         QFileDialog::ShowDirsOnly);
    if (path.isEmpty()) {
        return false;
    }
    return ResManager::getInstance()->loadLayers(path.toStdString());
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

void UiManager::resetAll() {
    while (auto item = _vbox_layout->takeAt(0)) {
        delete item;
    }
    _check_group.clear();
    _clicked = 0;
}

 void UiManager::updateUi() {
    resetAll();
    updateCheckBox();
    updateImgView();
 }

 void UiManager::updateImgView() {
    _main_window.updateImgView(ResManager::getInstance()->getCurrentImg());
 }

 void UiManager::message(std::string info) {
    info = "<p align='center'>" + info + "</p>";
    QMessageBox::information(&_main_window,
                             QString(""),
                             QString::fromStdString(info));
 }

}// end of namespace
