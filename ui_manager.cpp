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
    _main_window.setFixedSize(980, 550);
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
        if(!browseFile()) {
            message("empty or has been handled");
        }
        updateUi();
    }
        break;

    case save:
    {
        //do something
        string msg = ResManager::getInstance()->saveCurrentImg();
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
    // clear all the resource in res,no mater it success or not
    ResManager::getInstance()->resetAll();
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
    clc(_vbox_layout);
    _check_group.clear();
}

void UiManager::clc(QLayout* layout)
{
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            clc(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
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
