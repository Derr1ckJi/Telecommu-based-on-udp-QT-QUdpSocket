#include "Terminus.h"
#include "Advancced.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Terminus w;
    w.show();
//    Advancced c;
//    c.show();
    return a.exec();
}
