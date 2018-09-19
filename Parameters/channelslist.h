#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API ChannelsList: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(QStringList channels READ channels WRITE setChannels NOTIFY channelsChanged)
    Q_PROPERTY(QVector<bool> selected READ selected WRITE setSelected NOTIFY selectedChanged)
public:
    ChannelsList();
    ChannelsList(QString name, QString group, int index=0);

    bool setJSON(QJsonValue value);
    QJsonValue JSON();

    QJsonValue JSONattributes() override;

    QStringList channels() const;
    QVector<bool> selected() const;

public slots:

    void setChannels(QStringList channels);
    void setSelected(QVector<bool> selected);
    void setSelected(bool selected);

signals:

    void channelsChanged();
    void selectedChanged();

private:
    QStringList m_channels;
    QVector<bool> m_selected;
};

}
}
