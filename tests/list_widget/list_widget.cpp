#include <QTest>
#include <QLabel>
#include "wrapper.hpp"
#include <QPalette>

static const QVector<QColor> colorVector = { QColor("#d92727"),     // red
                                             QColor("#6023c2"),     // dark blue
                                             QColor("#1cbd52"),     // green
                                             QColor("#000000"),     // black
                                             QColor("#cf9e23"),     // orange
                                             QColor("#821d7f"),     // purple
                                             QColor("#e6f25c"),     // yellow
                                           };

class Test : public QObject {
    Q_OBJECT
private:
    QListWidget *mListWidget;
    WrapperStyleListWidget *mStyleListWidget;
public:
    Test() = default;
    ~Test() = default;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test() {
        QVERIFY(true);
    }
    void checkStyleCreate();
    void checkSetCssStyle();
    void checksetBackground();
    void setItemBackground();
    void setListWidgetItemSelectedBackground();
    void setListWidgetItemSelectedActiveBackground();
    void setListWidgetItemSelectedNoActiveBackground();

    void checkSetMargin_data();
    void checkSetMargin();

    void checkSetPadding_data();
    void checkSetPadding();

    void checkSetBorderWidth_data();
    void checkSetBorderWidth();

    void checkSetBorderRadius_data();
    void checkSetBorderRadius();
};

void Test::initTestCase()
{
    mListWidget = new QListWidget;
    mStyleListWidget = new WrapperStyleListWidget{mListWidget};
}

void Test::cleanupTestCase()
{
    delete mListWidget;
    delete mStyleListWidget;
}

void Test::checkStyleCreate()
{
    QCOMPARE(mListWidget, mStyleListWidget->getListWidget());
    QCOMPARE(mListWidget->styleSheet(), mStyleListWidget->getStyleSheet());
    QCOMPARE(mListWidget->styleSheet(), mStyleListWidget->getStyleSheetCopy());
    QVERIFY(mListWidget->styleSheet().size() != 0);
}

void Test::checkSetCssStyle()
{
    QString temp = "background: #7872D8;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    temp = "border-width: 0;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);
}

void Test::checksetBackground()
{
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setBackground(pink);

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QColor colorOrange = colorVector.at(4);
    mStyleListWidget->setBackground(colorOrange);

    temp = "background: #cf9e23;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());
}

void Test::setItemBackground()
{
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setItemBackground(pink);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QColor colorBlack = colorVector.at(3);
    mStyleListWidget->setItemBackground(colorBlack);

    temp = "background: #000000;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());
}

void Test::setListWidgetItemSelectedBackground() {
    QColor pink{0xbf, 0x22, 0xb0};
    mStyleListWidget->setItemSelectedBackground(pink);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());

    QString temp = "background: #bf22b0;";
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    temp = "background: #6023c2;";
    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted == -1);

    QColor colorDarkBlue = colorVector.at(1);
    mStyleListWidget->setItemSelectedBackground(colorDarkBlue);

    isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getStyleSheetCopy() != mStyleListWidget->getStyleSheet());
}

void Test::setListWidgetItemSelectedActiveBackground() {
    QColor colorRed = colorVector.at(0);
    mStyleListWidget->setItemSelectedActiveBackground(colorRed);

    QString temp = colorRed.name();
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getPreviousStyleSheet() != mStyleListWidget->getStyleSheet());
    isConsisted = mStyleListWidget->getPreviousStyleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted == -1);
}

void Test::setListWidgetItemSelectedNoActiveBackground() {
    QColor colorGreen = colorVector.at(2);
    mStyleListWidget->setItemSelectedActiveBackground(colorGreen);

    QString temp = colorGreen.name();
    qsizetype isConsisted = mListWidget->styleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted != -1);

    QVERIFY(mStyleListWidget->getPreviousStyleSheet() != mStyleListWidget->getStyleSheet());
    isConsisted = mStyleListWidget->getPreviousStyleSheet().indexOf(temp, 0);
    QVERIFY(isConsisted == -1);
}

void Test::checkSetMargin_data()
{
    QTest::addColumn<QMargins>("setMargins");
    QTest::addColumn<QString>("searchedMargins");
    QTest::newRow("listWidgetMargin") << QMargins{1,1,1,1} << "margin: 1 1 1 1;";
    QTest::newRow("listWidgetMargin") << QMargins{2,2,2,2} << "margin: 2 2 2 2;";
    QTest::newRow("listWidgetMargin") << QMargins{3,3,3,3} << "margin: 3 3 3 3;";
    QTest::newRow("listWidgetMargin") << QMargins{4,4,4,4} << "margin: 4 4 4 4;";
    QTest::newRow("listWidgetMargin") << QMargins{5,5,5,5} << "margin: 5 5 5 5;";
}

void Test::checkSetMargin()
{
    QFETCH(QMargins, setMargins);
    QFETCH(QString, searchedMargins);
    mStyleListWidget->setMargin(QMargins{1,1,1,1});
    mStyleListWidget->setItemMargin(QMargins{2,2,2,2});
    mStyleListWidget->setItemSelectedMargin(3,3,3,3);
    mStyleListWidget->setItemSelectedActiveMargin(4,4,4,4);
    mStyleListWidget->setItemSelectedNoActiveMargin(QMargins{5,5,5,5});
    QRegularExpression re( "QListWidget {(.)(\\ ){4}", QRegularExpression::DotMatchesEverythingOption);

    QString str;
    QCOMPARE(str = [&](){
        QRegularExpression re(searchedMargins);
        QRegularExpressionMatch match = re.match(mListWidget->styleSheet());
        if (match.hasMatch()) {
            QString str = match.captured();
            return str;
        }
        QString none = "None";
        return none;
    }(), searchedMargins);
}

void Test::checkSetPadding_data()
{
    QTest::addColumn<QString>("searchedPadding");
    QTest::newRow("listWidgetPadding") << "padding: 1 1 1 1;";
    QTest::newRow("listWidgetPadding") << "padding: 2 2 2 2;";
    QTest::newRow("listWidgetPadding") << "padding: 3 3 3 3;";
    QTest::newRow("listWidgetPadding") << "padding: 4 4 4 4;";
    QTest::newRow("listWidgetPadding") << "padding: 5 5 5 5;";
}

void Test::checkSetPadding()
{
    QFETCH(QString, searchedPadding);
    mStyleListWidget->setPadding(1,1,1,1);
    mStyleListWidget->setItemPadding(2,2,2,2);
    mStyleListWidget->setItemPaddingSelected(3,3,3,3);
    mStyleListWidget->setItemPaddingSelectedActive(4,4,4,4);
    mStyleListWidget->setItemPaddingSelectedNoActive(5,5,5,5);
    QRegularExpression re( "QListWidget {(.)(\\ ){4}", QRegularExpression::DotMatchesEverythingOption);

    QString str;
    QCOMPARE(str = [&](){
        QRegularExpression re(searchedPadding);
        QRegularExpressionMatch match = re.match(mListWidget->styleSheet());
        if (match.hasMatch()) {
            QString str = match.captured();
            return str;
        }
        QString none = "None";
        return none;
    }(), searchedPadding);
}

void Test::checkSetBorderWidth_data()
{
    QTest::addColumn<QString>("searchedBorderWidht");
    QTest::newRow("listWidgetBorderWidht") << "border-width: 10;";
    QTest::newRow("listWidgetBorderWidht") << "border-width: 5;";
    QTest::newRow("listWidgetBorderWidht") << "border-width: 3;";
    QTest::newRow("listWidgetBorderWidht") << "border-width: 0;";
    QTest::newRow("listWidgetBorderWidht") << "border-width: 12;";
}

void Test::checkSetBorderWidth()
{
    QFETCH(QString, searchedBorderWidht);
    mStyleListWidget->setBorderWidth(10);
    mStyleListWidget->setItemBorderWidth(5);
    mStyleListWidget->setItemSelectedBorderWidth(3);
    mStyleListWidget->setItemSelectedActiveBorderWidth(0);
    mStyleListWidget->setItemSelectedNoActiveBorderWidth(12);
    qDebug() << "\n\n" << mStyleListWidget->getStyleSheet() << "\n\n";
    QRegularExpression re( "QListWidget {(.)(\\ ){4}", QRegularExpression::DotMatchesEverythingOption);

    QString str;
    QCOMPARE(str = [&](){
        QRegularExpression re(searchedBorderWidht);
        QRegularExpressionMatch match = re.match(mListWidget->styleSheet());
        if (match.hasMatch()) {
            QString str = match.captured();
            return str;
        }
        QString none = "None";
        return none;
    }(), searchedBorderWidht);
}

void Test::checkSetBorderRadius_data()
{
    QTest::addColumn<QString>("searchedBorderRadius");
    QTest::newRow("listWidgetBorderRadius") << "border-radius: 1;";
    QTest::newRow("listWidgetBorderRadius") << "border-radius: 2;";
    QTest::newRow("listWidgetBorderRadius") << "border-radius: 3;";
    QTest::newRow("listWidgetBorderRadius") << "border-radius: 4;";
    QTest::newRow("listWidgetBorderRadius") << "border-radius: 5;";
}

void Test::checkSetBorderRadius()
{
    QFETCH(QString, searchedBorderRadius);
    mStyleListWidget->setBorderRadius(1);
    mStyleListWidget->setItemBorderRadius(2);
    mStyleListWidget->setItemSelectedBorderRadius(3);
    mStyleListWidget->setItemSelectedActiveBorderRadius(4);
    mStyleListWidget->setItemSelectedNoActiveBorderRadius(5);
    qDebug() << "\n\n" << mStyleListWidget->getStyleSheet() << "\n\n";
    QRegularExpression re( "QListWidget {(.)(\\ ){4}", QRegularExpression::DotMatchesEverythingOption);

    QString str;
    QCOMPARE(str = [&](){
        QRegularExpression re(searchedBorderRadius);
        QRegularExpressionMatch match = re.match(mListWidget->styleSheet());
        if (match.hasMatch()) {
            QString str = match.captured();
            return str;
        }
        QString none = "None";
        return none;
    }(), searchedBorderRadius);
}

QTEST_MAIN(Test)
#include "list_widget.moc"








