#include "line.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Line w;
    w.show();

    return a.exec();
}
