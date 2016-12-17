#include "uimainwindow.h"
#include "ui_manager.h"
#include "ui_uimainwindow.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
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

void UIMainWindow::updateImgView(const cv::Mat& img) {
    using namespace cv;
    // get size
    const int height = ui->Display->height();
    const int width = ui->Display->width();
    Mat display;

    if (!img.empty()) {
        QImage imdisplay;
        display = img;
        cv::resize(display, display, Size(width, height), 0,0,INTER_LINEAR);
        cv::cvtColor(display, display, CV_BGR2RGB);
        imdisplay = QImage((uchar*)display.data, display.cols,
                         display.rows, display.step, QImage::Format_RGB888);
        ui->Display->setPixmap(QPixmap::fromImage(imdisplay));
        std::cout << display.cols << display.rows << display.step;
    }
    else {
        //ui->Display->setPixmap(NULL);
        ui->Display->clear();
    }



}

void UIMainWindow::resetImgView() {

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

