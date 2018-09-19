#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API Select: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value NOTIFY valueChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY valueChanged)
    Q_PROPERTY(QStringList options READ options WRITE setOptions NOTIFY optionsChanged)
public:
    Select();
    Select(QString name, QString group, int index=0);

    QVariant value();

    void setOptions(QStringList options);
    void setOptions(QList< QPair<QString, QVariant> > options);

    QStringList options();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();

    QJsonValue JSONattributes() override;

    int index() const;

public slots:
    void setIndex(int index);
    void addOption(QString name);
    void addOption(QString name, QVariant value);
    void addOptions(QStringList names);

signals:
    void optionsChanged();
    void valueChanged();

private:
    QList<QPair<QString, QVariant> > m_options;
    int m_index;
};

}
}

