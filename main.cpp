#include "gradientdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    GradientDialog d;
    d.show();
    return a.exec();
}
