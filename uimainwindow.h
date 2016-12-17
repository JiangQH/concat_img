#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
namespace Ui {
class UIMainWindow;
}

class UIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIMainWindow(QWidget *parent = 0);
    ~UIMainWindow();
    void setGropubox(QLayout * layout);
    void updateImgView(const cv::Mat& img);
    void resetImgView();
private slots:
    void on_browseButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::UIMainWindow *ui;
    void connectSignalAndSlots();
};

#endif // UIMAINWINDOW_H
