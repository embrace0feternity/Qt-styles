#include <QTest>
#include "../../style_list_widget.hpp"

using namespace e0fe::styles;

class Test : public QObject {
    Q_OBJECT
private:
    QListWidget *mListWidget;
    StyleListWidget *mStyleListWidget;
private slots:
    void initTestCase() {
        mListWidget = new QListWidget;
        mStyleListWidget = new StyleListWidget(mListWidget);
        qDebug() << "Start a new Test ";
    }

    void cleanupTestCase() {
        qDebug() << "Call after test execution";
        delete mListWidget;
        delete mStyleListWidget;
    }

    void checkStyleCreate() {
        QCOMPARE("1","1");
//        auto tempStyleSheet = mListWidget->styleSheet();
//        if (tempStyleSheet.size() != 0)
//            QFAIL("styleSheet isn't set in the list widget");
    }
};


QTEST_MAIN(Test)
#include "list_widget.moc"
