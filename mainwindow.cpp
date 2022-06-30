#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace e0fe::styles;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , listWidget(new QListWidget)
{
    ui->setupUi(this);
    [[maybe_unused]] StyleListWidget *mStyleListWidget = new StyleListWidget(listWidget);
    QColor color{0xd9, 0x27, 0x27};
    mStyleListWidget->setBackground(color);
    qDebug() << listWidget->styleSheet();
    QStringList stringList = {"#d92727", // red
                             "#6023c2",  // dark bluer
                             "#1cbd52",  // green
                             "#cf9e23",  // orange
                             "#000000"}; // black

    mStyleListWidget->setItemSelectedBackground(QColor{0x1c, 0xbd, 0x52});

    qDebug() << "\n\n" << mStyleListWidget->getStyleSheet();

    foreach (QString str, stringList){

        QPushButton *p = new QPushButton(listWidget);
        p->setText(str);

        QListWidgetItem *i = new QListWidgetItem;
        listWidget->addItem(i);
        listWidget->setItemWidget(i, p);

        QColor color(str);
        mStyleListWidget->setItemBackground(color);
    }


//    mStyleListWidget->setBorderWidth(15);
//    mStyleListWidget->setItemSelectedActiveBorderWidth(10);


    qDebug() << "\n\n" << mStyleListWidget->getStyleSheet();
    ui->vert->addWidget(listWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

