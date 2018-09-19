#pragma once
#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API String: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
public:
    String();
    String(QString name, QString group, int index=0);

    QString value();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();

public slots:
    void setValue(QString value);

signals:
    void valueChanged(QString value);

private:
    QString m_value;
};

}
}

