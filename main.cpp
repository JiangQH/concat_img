#include "uimainwindow.h"
#include "ui_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jqh::UiManager::getInstance()->run();
    //UIMainWindow w;
    //w.show();

    return a.exec();
}
