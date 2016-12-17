#include "uiimgcheck.h"
#include "ui_manager.h"
#include <QString>
#include <string>
UIImgCheck::UIImgCheck(int id, QWidget *parent) :
    QCheckBox(QString::fromStdString(std::to_string(id)), parent)
{
    _id = id;
    connect(this, SIGNAL(stateChanged(int)), this, SLOT(on_state_changed(int)));
}

UIImgCheck::~UIImgCheck() {
    // somthing
}


void UIImgCheck::on_state_changed(int checkState) {
    // do somthing
    if (checkState == Qt::Unchecked) {
        // unchecked
        jqh::Signal s(jqh::unchecked, _id);
        jqh::UiManager::getInstance()->receiveSignal(s);
    }
    else {
        //checked
        jqh::Signal s(jqh::checked, _id);
        jqh::UiManager::getInstance()->receiveSignal(s);
    }
}




