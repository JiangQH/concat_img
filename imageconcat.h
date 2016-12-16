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

private:
    Ui::ImageConcat *ui;
};

#endif // IMAGECONCAT_H
