#include <QTest>

class Test : public QObject {
    Q_OBJECT
private slots:
    void checkTrue() {
        QString str = "True";
        QVERIFY(str == "True");
    }
};


QTEST_MAIN(Test)
#include "main.moc"

