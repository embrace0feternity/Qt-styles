#include <QTest>
#include <QLabel>
#include "wrapper.hpp"
#include <QPalette>

class Test : public QObject {
    Q_OBJECT
private:
    QListWidget *mListWidget;
    WrapperStyleListWidget *mStyleListWidget;
private slots:
    void initTestCase();
    void cleanupTestCase();

    void checkStyleCreate();                            // 1
    void checkSetCssStyle();                            // 2
    void checkSetListWidgetBackground();                // 3
    void setListWidgetItemBackground();                 // 4
    void setListWidgetItemSelectedBorderColor();        // 5
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
    QString styleSheet = mStyleListWidget->getStyleSheet();
    QString styleSheetCopy = mStyleListWidget->getStyleSheetCopy();

    QCOMPARE(mListWidget, mStyleListWidget->getListWidget());
    QCOMPARE(mListWidget->styleSheet(), styleSheet);
    QCOMPARE(styleSheet, styleSheetCopy);
    QVERIFY(styleSheet.size() != 0);
}

void Test::checkSetCssStyle()
{
    QCOMPARE(mListWidget->contentsMargins(), QMargins(3, 20, 3, 20));

    QString temp = "background: #7872D8;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    temp = "border: none;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);
}

void Test::checkSetListWidgetBackground()
{
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setListWidgetBackground(pink);

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QStringList stringList = {"#d92727", // red
                             "#6023c2",  // dark blue
                             "#1cbd52",  // green
                             "#000",     // black
                             "#cf9e23"}; // orange

    foreach (QString str, stringList){
        QColor color{str};
        mStyleListWidget->setListWidgetBackground(color);
    }

    temp = "background: #cf9e23;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());
}

void Test::setListWidgetItemBackground()
{
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setListWidgetItemBackground(pink);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QStringList stringList = {"#d92727", // red
                             "#6023c2",  // dark blue
                             "#1cbd52",  // green
                             "#cf9e23",  // black
                             "#000000"}; // orange 000

    foreach (QString str, stringList){
        QColor color{str};
        mStyleListWidget->setListWidgetItemBackground(color);
    }

    temp = "background: #000000;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());
}

void Test::setListWidgetItemSelectedBorderColor() {
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setListWidgetItemSelectedBackground(pink);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QStringList stringList = {"#d92727", // red
                             "#6023c2",  // dark blue
                             "#1cbd52"}; // green

    foreach (QString str, stringList){
        QColor color{str};
        mStyleListWidget->setListWidgetItemSelectedBackground(color);
    }

    temp = "background: #000000;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted == -1);

    temp = "background: #1cbd52;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());

}

QTEST_MAIN(Test)
#include "list_widget.moc"

