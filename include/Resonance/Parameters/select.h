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

    QVariant value() const;

    void setOptions(QStringList options);
    void setOptions(QList< QPair<QString, QVariant> > options);

    QStringList options() const;
    QList<QPair<QString, QVariant> > optionsWithValues() const;

    bool setJSON(QJsonValue value) override;
    QJsonValue JSON() override;

    QJsonValue JSONattributes() override;

    int index() const;

public slots:
    void setIndex(int index);
    void addOption(QString name);
    void addOption(QString name, QVariant value);
    void addOptions(QStringList names);

signals:
    void optionsChanged();
    void valueChanged(int oldIndex);

private:
    QList<QPair<QString, QVariant> > m_options;
    int m_index;
};

}
}

