#ifndef IMAGECONCAT_H
#define IMAGECONCAT_H

#include <QWidget>

namespace Ui {
class ImageConcat;
}

class ImageConcat : public QWidget
{
    Q_OBJECT

public:
    explicit ImageConcat(QWidget *parent = 0);
    ~ImageConcat();


private slots:
    void onBrowseFiles();

    void onSaveData();

    void onCheckStateChanged(int arg1);


private:
    Ui::ImageConcat *ui;

    // to connect the signal and slots
    void connectSignalAndSlots();
};

#endif // IMAGECONCAT_H
