#include "mainwindow.h"
#include <QApplication>
#include <typeinfo>
#include <QLabel>
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
