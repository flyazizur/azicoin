// AZIcoin Qt units: add AZI, mAZI, uAZI and ZOO (smallest unit)
#include "bitcoinunits.h"
#include <QStringList>

QList<BitcoinUnits::Unit> BitcoinUnits::availableUnits()
{
    QList<BitcoinUnits::Unit> unitlist;
    unitlist.append(AZI);
    unitlist.append(mAZI);
    unitlist.append(uAZI);
    unitlist.append(ZOO);
    return unitlist;
}

bool BitcoinUnits::valid(int unit)
{
    switch(unit)
    {
    case AZI:
    case mAZI:
    case uAZI:
    case ZOO:
        return true;
    default:
        return false;
    }
}

QString BitcoinUnits::longName(int unit)
{
    switch(unit)
    {
    case AZI: return QString("AZI");
    case mAZI: return QString("mAZI");
    case uAZI: return QString::fromUtf8("μAZI");
    case ZOO: return QString("zoo");
    default: return QString("???");
    }
}

QString BitcoinUnits::description(int unit)
{
    switch(unit)
    {
    case AZI: return QString("AZI");
    case mAZI: return QString("Milli-AZI (1 / 1,000)");
    case uAZI: return QString("Micro-AZI (1 / 1,000,000)");
    case ZOO: return QString("zoo (1 AZI = 100,000,000 zoo)");
    default: return QString("???");
    }
}

qint64 BitcoinUnits::factor(int unit)
{
    switch(unit)
    {
    case AZI: return 100000000;
    case mAZI: return 100000;
    case uAZI: return 100;
    case ZOO: return 1;
    default: return 100000000;
    }
}

int BitcoinUnits::decimals(int unit)
{
    switch(unit)
    {
    case AZI: return 8;
    case mAZI: return 5;
    case uAZI: return 2;
    case ZOO: return 0;
    default: return 0;
    }
}