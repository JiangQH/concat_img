#include "uimainwindow.h"
#include "ui_manager.h"
#include "ui_uimainwindow.h"
#include <iostream>
#include <QLayout>
UIMainWindow::UIMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIMainWindow)
{
    ui->setupUi(this);
}

UIMainWindow::~UIMainWindow()
{
    delete ui;
}

void UIMainWindow::setGropubox(QLayout * layout) {
    ui->checkGroup->setFlat(true);
    ui->checkGroup->setLayout(layout);
}

void UIMainWindow::connectSignalAndSlots() {
    // signal connect
    connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(on_browseButton_clicked()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));
}

// slots functions

void UIMainWindow::on_browseButton_clicked()
{
    //tell the ui_manager, that browse clicked
    jqh::UiManager::getInstance()->receiveSignal(jqh::browse);
}

void UIMainWindow::on_saveButton_clicked()
{
    //tell the ui_manager, that save clicked
    jqh::UiManager::getInstance()->receiveSignal(jqh::save);
}

