#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include "uimainwindow.h"
#include "uiimgcheck.h"
#include <vector>
#include <string>
#include <QCheckBox>
#include <QVBoxLayout>
namespace jqh {
enum SenderType{
    browse,
    save,
    checked,
    unchecked
};
struct Signal {
  SenderType _sender; // who send the signal
  int _id;  // the id the the sender, used only when sender is checkbox
  Signal(SenderType type, int id=-1) {
      _sender = type;
      _id = id;
  }
};
class UiManager
{
public:
    static UiManager* getInstance();
    void run();
    void receiveSignal(Signal s);
    ~UiManager();
private:
    UiManager();
    UIMainWindow _main_window;
    std::vector<UIImgCheck*> _check_group;
    QVBoxLayout *_vbox_layout;
    int _clicked;

    void browseFile();
    void updateUi();
    void updateCheckBox();
    void updateImgView();
    void resetAll();
};// end of class

}// end of namespace
#endif // UI_MANAGER_H
