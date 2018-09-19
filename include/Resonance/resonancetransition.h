#pragma once

#include "common.h"
#include <QSignalTransition>

namespace Resonance {

class RESONANCE_API ResonanceTransition: public QSignalTransition
{
    Q_OBJECT
public:
    ResonanceTransition(QString name, QState *sourceState);

    QString name();

protected:
    bool eventTest(QEvent *e) override;

protected:
    QString m_name;
};

}
