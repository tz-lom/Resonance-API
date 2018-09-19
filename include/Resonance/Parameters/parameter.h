#pragma once

#include <Resonance/common.h>
#include <QObject>
#include <QJsonArray>

namespace Resonance {
namespace Parameters {

class RESONANCE_API Parameter: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString group READ group WRITE setGroup NOTIFY groupChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)
public:
    Parameter();
    Parameter(QString name, QString group, int index=0);

    void setFullDescription(QString name, QString label=QString(), int index=0, QString group="default");
    void registerFullDescription(QString name, QString label=QString(), int index=0, QString group="default");

    QString name();
    QString group();
    QString label();
    bool isEnabled();

    virtual bool setJSON(QJsonValue value) = 0;
    virtual QJsonValue JSON() = 0;
    virtual QJsonValue JSONattributes();


    int index() const;

signals:
    void triggerUpdate();
    void enabledChanged();
    void nameChanged(QString name);
    void groupChanged(QString group);
    void indexChanged(int index);

    void labelChanged(QString label);

public slots:
    void setLabel(QString label);
    void setEnabled(bool enabled);
    void setName(QString name);
    void setGroup(QString group);
    void setIndex(int index);

private:
    QString m_name;
    QString m_group;
    QString m_label;
    bool m_enabled;
    int m_index;
};

}
}

