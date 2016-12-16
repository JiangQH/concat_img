#include "imageconcat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageConcat w;
    w.show();

    return a.exec();
}
