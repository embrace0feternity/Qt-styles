#include <QTest>
#include <QLabel>
#include "wrapper.hpp"

class Test : public QObject {
    Q_OBJECT
private:
    QListWidget *mListWidget;
    WrapperStyleListWidget *mStyleListWidget;
private slots:
    void initTestCase();
    void cleanupTestCase();

    void checkStyleCreate();            // 1
    void checkSetStyleBlue();           // 2
};

void Test::initTestCase()
{
    qDebug() << "\n";
    mListWidget = new QListWidget;
    mStyleListWidget = new WrapperStyleListWidget{mListWidget};
}

void Test::cleanupTestCase()
{
    delete mStyleListWidget;
    delete mListWidget;
}

void Test::checkStyleCreate()
{
    auto tempStyleSheet = mListWidget->styleSheet();
    const QListWidget *tempListWidget = mStyleListWidget->getListWidget();
    QCOMPARE(tempListWidget, mListWidget);

    QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheet());
    QCOMPARE(tempStyleSheet.size(), mStyleListWidget->getStyleSheet().size());
}

void Test::checkSetStyleBlue()
{
    auto tempStyleSheet = mListWidget->styleSheet();
    QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheet());
    QCOMPARE(tempStyleSheet, mStyleListWidget->getStyleSheetCopy());

}

QTEST_MAIN(Test)
#include "list_widget.moc"

