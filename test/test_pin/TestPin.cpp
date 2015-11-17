
#include <QtCore>
#include <QtTest>
#include <QDebug>

#include "SysfsGPIO.h"

class TestPin : public QObject
{
    Q_OBJECT

    private:
    public:

    private slots:
        void test_basic();
};


void TestPin::test_basic()
{
    QCOMPARE(GPIO_Pin11, SysfsGPIO::checkGPIO( 17));

    QCOMPARE(GPIO_NONE,  SysfsGPIO::checkGPIO(  0));
    QCOMPARE(GPIO_NONE,  SysfsGPIO::checkGPIO(100));


    QCOMPARE(GPIO_Pin11, SysfsGPIO::checkGPIO( QString(" 17")));
    QCOMPARE(GPIO_NONE,  SysfsGPIO::checkGPIO( QString("100")));

    QCOMPARE(GPIO_Pin11, SysfsGPIO::checkGPIO( QString("gpio17")));
    QCOMPARE(GPIO_NONE,  SysfsGPIO::checkGPIO( QString("gpio100")));

    QCOMPARE(GPIO_NONE,  SysfsGPIO::checkGPIO( QString("nisse")));
}

QTEST_MAIN(TestPin)
#include "TestPin.moc"
