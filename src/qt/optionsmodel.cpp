// AZIcoin: add default required confirmations = 30
#include "optionsmodel.h"
#include <QSettings>

OptionsModel::OptionsModel(QObject *parent) : QAbstractListModel(parent)
{
    QSettings settings;
    // If not present, set default required confirmations to 30
    if (!settings.contains("requiredconfirmations")) {
        settings.setValue("requiredconfirmations", 30);
    }
}