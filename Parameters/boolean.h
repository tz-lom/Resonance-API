#pragma once

#include "parameter.h"

namespace Resonance {
namespace Parameters {

class RESONANCE_API Boolean: public Parameter
{
    Q_OBJECT
    Q_PROPERTY(bool value READ value WRITE setValue NOTIFY valueChanged)
public:
    Boolean();
    Boolean(QString name, QString group, int index=0);

    bool value();

    bool setJSON(QJsonValue value);
    QJsonValue JSON();

public slots:
    void setValue(bool value);

signals:
    void valueChanged(bool value);

private:
    bool m_value;
};

}
}

