#include "mainwindow.h"
#include <QApplication>
#include <typeinfo>
#include <QLabel>
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton b, c;
    QLabel l;
    qDebug() << "\n" << typeid (b).name();
    qDebug() << "\n" << typeid (l).name();
    qDebug() << "\n" << typeid (c).name();
    w.show();
    return a.exec();
}
