#include <QTest>
#include <QLabel>
#include "wrapper.hpp"

class Test : public QObject {
    Q_OBJECT
private:
    QListWidget *mListWidget;
    WrapperStyleListWidget *mStyleListWidget;
private slots:
    void initTestCase() {
        mListWidget = new QListWidget;
        mStyleListWidget = new WrapperStyleListWidget{mListWidget};
    }

    void cleanupTestCase() {
        qDebug() << "\n";
        delete mStyleListWidget;
        delete mListWidget;
    }

    void checkStyleCreate() {
        auto tempStyleSheet = mListWidget->styleSheet();
        //const QListWidget *tempListWidget = mStyleListWidget->getListWidget();
        //QCOMPARE(tempListWidget, mListWidget);

        QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheet());
        QCOMPARE(tempStyleSheet.size(), mStyleListWidget->getStyleSheet().size());
    }

    void checkSetStyleBlue() {
        QLabel l;
        l.setText("qwer");
        QCOMPARE(l.text(), "qwer");


        mStyleListWidget->setStyleSheetBlue();
//        auto tempStyleSheet = mListWidget->styleSheet();
//        QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheet());
//        QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheetCopy());

    }
};


QTEST_MAIN(Test)
#include "list_widget.moc"

