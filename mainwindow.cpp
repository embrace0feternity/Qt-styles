#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace e0fe::styles;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , listWidget(this)
    , ui(new Ui::MainWindow)
{

    [[maybe_unused]] StyleListWidget *st = new StyleListWidget{&listWidget};
    ui->setupUi(this);
    QPushButton *p1 = new QPushButton(this);
    QPushButton *p2 = new QPushButton(this);
    QPushButton *p3 = new QPushButton(this);


    QListWidgetItem *i1 = new QListWidgetItem;
    QListWidgetItem *i2 = new QListWidgetItem;
    QListWidgetItem *i3 = new QListWidgetItem;

    listWidget.addItem(i1);
    listWidget.addItem(i2);
    listWidget.addItem(i3);
    i1->setHidden(true);
    i2->setHidden(true);
    i3->setHidden(true);
    listWidget.setItemWidget(i1, p1);
    listWidget.setItemWidget(i2, p2);
    listWidget.setItemWidget(i3, p3);
    ui->verticalLayout->addWidget(&listWidget);
    i1->setHidden(false);
    i2->setHidden(false);
    i3->setHidden(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

