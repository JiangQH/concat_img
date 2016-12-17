#ifndef IMAGECONCAT_H
#define IMAGECONCAT_H

#include <QWidget>
#include <QCheckBox>
#include <vector>
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

    void onCheckStateChanged(int arg1);


private:
    Ui::ImageConcat *ui;
    std::vector<QCheckBox*> _check_group;// the check box in check group

    // to connect the signal and slots
    void connectSignalAndSlots();
    // create the check group
    void createCheckGroup(int count);
};

#endif // IMAGECONCAT_H
