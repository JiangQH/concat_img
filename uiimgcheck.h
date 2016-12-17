#ifndef UIIMGCHECK_H
#define UIIMGCHECK_H

#include <QObject>
#include <QCheckBox>
class UIImgCheck : public QCheckBox
{
    Q_OBJECT
public:
    explicit UIImgCheck(int id, QWidget *parent = 0);
    ~UIImgCheck();

private:
    int _id;

private slots:
    void on_state_changed(int);


};

#endif // UIIMGCHECK_H
