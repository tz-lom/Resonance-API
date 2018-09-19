#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API BipolarChannelsList: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(QStringList channels READ channels WRITE setChannels NOTIFY channelsChanged)
    Q_PROPERTY(QVariantList selected READ selected WRITE setSelected NOTIFY selectedChanged)
public:
    BipolarChannelsList();

    bool setJSON(QJsonValue value) override;
    QJsonValue JSON() override;

    QJsonValue JSONattributes() override;
    QStringList channels() const;
    QVariantList selected() const;

public slots:
    void setChannels(QStringList channels);
    void setSelected(QVariantList selected);

signals:
    void channelsChanged(QStringList channels);
    void selectedChanged(QVariantList selected);

protected:
    QStringList m_channels;
    QVariantList m_selected;
};

}
}
